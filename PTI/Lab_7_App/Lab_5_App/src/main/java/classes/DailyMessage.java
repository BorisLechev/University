package classes;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;
import java.io.IOException;

@WebServlet(urlPatterns = "/dailyMessage")
public class DailyMessage extends HttpServlet {
    private static final long serialVersionUID = 1L;

    public DailyMessage() {
        super();
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        Cookie cookie = new Cookie("seen_cookie","yes");
        cookie.setMaxAge(24 * 60 * 60);  // 24 hours.

        response.addCookie(cookie);
        HttpSession session=request.getSession();
        User userFromSession = (User)session.getAttribute("user");

        request.setAttribute("username", userFromSession.getUsername());
        request.setAttribute("name", userFromSession.getName());
        request.setAttribute("password", userFromSession.getPassword());
        request.setAttribute("age", userFromSession.getAge());
        request.setAttribute("email", userFromSession.getEmail());
        request.setAttribute("id", userFromSession.getId());

        RequestDispatcher bb = request.getRequestDispatcher("views/profilePage/profilePage.jsp");
        bb.forward(request, response);
    }
}
package classes;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

@WebServlet(urlPatterns = "/profile/*")
public class UserProfile extends HttpServlet {
    private static final long serialVersionUID = 1L;

    public UserProfile() {
        super();
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String url = request.getRequestURL().toString();
        String id = url.split("/")[4];

        HttpSession session = request.getSession();

        if(session.getAttribute("user") == null) {
            RequestDispatcher bb = request.getRequestDispatcher("login.jsp");
            bb.forward(request, response);
        }

        for (User user: Register.users) {
            if(Integer.toString(user.getId()).equals(id)) {
                request.setAttribute("username", user.getUsername());
                request.setAttribute("name", user.getName());
                request.setAttribute("password", user.getPassword());
                request.setAttribute("age", user.getAge());
                request.setAttribute("email", user.getEmail());
                request.setAttribute("id", user.getId());

                request
                    .getRequestDispatcher("/views/profilePage/profilePage.jsp")
                    .forward(request, response);
            }
        }
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doGet(request, response);
    }
}
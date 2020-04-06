package classes;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet(urlPatterns = "/edit/*")
public class EditProfile extends HttpServlet {
    private static final long serialVersionUID = 1L;

    public EditProfile() {
        super();
    }

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String url = request.getRequestURL().toString();
        String id = url.split("/")[4];

        for (User user: Register.users) {
            response.getWriter().write(Integer.toString(user.getId()) +  " <br>" + id);

            if(Integer.toString(user.getId()).equals(id)) {
                request.setAttribute("username", user.getUsername());
                request.setAttribute("name", user.getName());
                request.setAttribute("password", user.getPassword());
                request.setAttribute("age", user.getAge());
                request.setAttribute("email", user.getEmail());
                request.setAttribute("id", user.getId());

                request
                    .getRequestDispatcher("/editProfile.jsp")
                    .forward(request, response);
            }
        }

    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        for (User user: Register.users) {
            String id = request.getRequestURL().toString().split("/")[5];

            if (id.equals(Integer.toString(user.getId()))) {
                user.setUsername(request.getParameter("username").toString());
                user.setName(request.getParameter("name").toString());
                user.setPassword(request.getParameter("password").toString());
                user.setAge(request.getParameter("age").toString());
                user.setEmail(request.getParameter("email").toString());

                request.setAttribute("username", user.getUsername());
                request.setAttribute("name", user.getName());
                request.setAttribute("password", user.getPassword());
                request.setAttribute("age", user.getAge());
                request.setAttribute("email", user.getEmail());
                request.setAttribute("id", user.getId());

            }
        }

        doGet(request, response);
    }
}

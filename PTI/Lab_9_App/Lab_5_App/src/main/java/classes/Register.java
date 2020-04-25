package classes;

import java.io.IOException;
import java.util.*;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

@WebServlet(urlPatterns = "/register")
public class Register extends HttpServlet {
    private static final long serialVersionUID = 1L;

    public static ArrayList<User> users;

    public void init() throws ServletException
    {
        users = new ArrayList<User>();
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        if(session.getAttribute("user") == null) {
            RequestDispatcher bb = request.getRequestDispatcher("register.jsp");
            bb.forward(request, response);
        }
        else {
            User userFromSession = (User)session.getAttribute("user");

            request.setAttribute("username", userFromSession.getUsername());
            request.setAttribute("name", userFromSession.getName());
            request.setAttribute("password", userFromSession.getPassword());
            request.setAttribute("age", userFromSession.getAge());
            request.setAttribute("email", userFromSession.getEmail());
            request.setAttribute("id", userFromSession.getId());

            RequestDispatcher profile = request.getRequestDispatcher("views/profilePage/profilePage.jsp");
            profile.forward(request, response);
        }
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
    {
        String firstName = request.getParameter("firstName");
        String username = request.getParameter("username");
        String password = request.getParameter("password");
        String confirmPassword = request.getParameter("confirmPassword");

        if (firstName.isEmpty() || username.isEmpty() || password.isEmpty() || confirmPassword.isEmpty())
        {
            RequestDispatcher req = request.getRequestDispatcher("views/register/errors/invalidCredentials.jsp");
            req.include(request, response);
        }

        if (!password.equals(confirmPassword))
        {
            RequestDispatcher req = request.getRequestDispatcher("views/register/errors/differentPasswords.jsp");
            req.include(request, response);
        }

        if (!firstName.isEmpty() && !username.isEmpty() && !password.isEmpty() && !confirmPassword.isEmpty())
        {
            if (users.size() > 0) {
                for (User user: Register.users) {
                    if(user.getUsername().equals(username)) {
                        RequestDispatcher req = request.getRequestDispatcher("views/register/errors/usernameExists.jsp");
                        req.forward(request, response);
                        return;
                    }
                }
            }

            users.add(new User(firstName, username, password, this.users.size() + 1));

            request.setAttribute("name", firstName);
            request.setAttribute("username", username);
            request.setAttribute("password", password);

            response.sendRedirect("./login.jsp");
        }
    }
}
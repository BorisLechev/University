package classes;

import java.io.IOException;
import java.util.*;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet(urlPatterns = "/register")
public class Register extends HttpServlet {
    private static final long serialVersionUID = 1L;

    public static ArrayList<User> users;

    public void init() throws ServletException
    {
        users = new ArrayList<User>();
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
            req.forward(request, response);
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

//            RequestDispatcher bb = request.getRequestDispatcher("views/profilePage/profilePage.jsp");
//            bb.forward(request, response);
            response.sendRedirect("./login.jsp");
        }
    }
}
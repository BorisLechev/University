package controllers;

import models.User;
import models.UserRepository;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet(urlPatterns = "/register")
public class Register extends HttpServlet {
    public UserRepository repository = UserRepository.getInstance();

//    public void init() throws ServletException {
//        this.repository = new UserRepository();
//    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.sendRedirect("register.jsp");
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response)
        throws ServletException, IOException {
        String fullName = request.getParameter("fullName");
        String email = request.getParameter("email");
        String password = request.getParameter("password");
        String confirmPassword = request.getParameter("confirmPassword");

        if (fullName.isEmpty() || email.isEmpty() || password.isEmpty() || confirmPassword.isEmpty()) {
//            RequestDispatcher req = request.getRequestDispatcher("views/register/errors/invalidCredentials.jsp");
//            req.include(request, response);
            response.sendRedirect("errors/invalidCredentials.jsp");
            return;
        }

        if (!password.equals(confirmPassword)) {
            response.sendRedirect("errors/differentPasswords.jsp");
            return;
        }

        if (!fullName.isEmpty() && !email.isEmpty() && !password.isEmpty() && !confirmPassword.isEmpty()) {
            User user = new User(fullName, email, password, this.repository.getSize() + 1);

            for (User currentUser : this.repository.getUsers()) {
                if (currentUser.getEmail().equals(email)) {
                    response.sendRedirect("errors/usernameExists.jsp");
                    return;
                }
            }

            this.repository.addUser(user);

            response.sendRedirect("./login.jsp");
        }
    }
}

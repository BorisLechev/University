package controllers;

import models.User;
import models.UserRepository;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

@WebServlet(urlPatterns = "/register")
public class Register extends HttpServlet {
    public UserRepository repository = UserRepository.getInstance();

    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        HttpSession session = request.getSession();

        if(session.getAttribute("user") == null) {
            response.sendRedirect("register.jsp");
        } else {
            User userFromSession = (User)session.getAttribute("user");

            request.setAttribute("email", userFromSession.getEmail());
            request.setAttribute("fullName", userFromSession.getFullName());
            request.setAttribute("password", userFromSession.getPassword());
            request.setAttribute("age", userFromSession.getAge());
            request.setAttribute("email", userFromSession.getEmail());
            request.setAttribute("id", userFromSession.getId());

            RequestDispatcher profile = request.getRequestDispatcher("profilePage.jsp");
            profile.forward(request, response);
        }
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response)
        throws ServletException, IOException {
        String fullName = request.getParameter("fullName");
        String email = request.getParameter("email");
        String password = request.getParameter("password");
        String confirmPassword = request.getParameter("confirmPassword");

        if (fullName.isEmpty() || email.isEmpty() || password.isEmpty() || confirmPassword.isEmpty()) {
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

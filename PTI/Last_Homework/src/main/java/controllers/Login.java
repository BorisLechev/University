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

@WebServlet(urlPatterns = "/login")
public class Login extends HttpServlet {
    public UserRepository repository = UserRepository.getInstance();

    protected void doGet(HttpServletRequest request, HttpServletResponse response)
        throws ServletException, IOException {
        HttpSession session = request.getSession();

        if(session.getAttribute("user") == null) {
            response.sendRedirect("login.jsp");
        }
        else {
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
        String email = request.getParameter("email");
        String password = request.getParameter("password");

        if(email.isEmpty() || password.isEmpty()) {
            RequestDispatcher req = request.getRequestDispatcher("views/login/errors/requiredFields.jsp");
            req.include(request, response);
        } else {
            User getEmail = this.repository.getUserByEmail(email);
            String getPassword = getEmail.getPassword();

            if (this.repository.getUserByEmail(email) != null &&
                    this.repository.getUserByEmail(email).getPassword().equals(password)) {
                int id = this.repository.getUserByEmail(email).getId();

                HttpSession session = request.getSession();
                session.setAttribute("user", this.repository.getUserById(id));
                session.setAttribute("user_id", Integer.toString(id));

                response.sendRedirect("edit/" + id);
                return;
            }
        }

        RequestDispatcher bb = request.getRequestDispatcher("errors/invalidCredentials.jsp");
        bb.forward(request, response);
    }
}

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

@WebServlet(urlPatterns = "/edit/*")
public class EditProfile extends HttpServlet {
    private UserRepository repository = UserRepository.getInstance();

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String url = req.getRequestURL().toString();
        int id = Integer.parseInt(url.split("/")[4]);

        HttpSession session = req.getSession();

        if (session.getAttribute("user") == null) {
            resp.sendRedirect("/login.jsp");
            return;
        }

        int userId = Integer.parseInt(session.getAttribute("user_id").toString());
        if (userId != id) {
            resp.sendRedirect("/login.jsp");
            return;
        }

        User user = this.repository.getUserById(id);

        if (user != null) {
            req.setAttribute("id", user.getId());
            req.setAttribute("fullName", user.getFullName());
            req.setAttribute("email", user.getEmail());
            req.setAttribute("age", user.getAge());
            req.setAttribute("password", user.getPassword());

            req
                .getRequestDispatcher("/editProfile.jsp")
                .forward(req, resp);
        }
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String url = req.getRequestURL().toString();
        int id = Integer.parseInt(url.split("/")[4]);
        User user = this.repository.getUserById(id);

        if (user != null) {
            if (req.getParameter("fullName") != null) {
                user.setFullName(req.getParameter("fullName"));
                user.setPassword(req.getParameter("password"));
            } else {
                user.setAge(Integer.parseInt(req.getParameter("age")));
                user.setEmail(req.getParameter("email"));
            }

            req.setAttribute("id", user.getId());
            req.setAttribute("fullName", user.getFullName());
            req.setAttribute("email", user.getEmail());
            req.setAttribute("age", user.getAge());
        }

        doGet(req, resp);
    }
}

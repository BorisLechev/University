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

@WebServlet(urlPatterns = "/profile/*")
public class UserProfile extends HttpServlet {
    private UserRepository repository = UserRepository.getInstance();

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String url = req.getRequestURL().toString();
        int id = Integer.parseInt(url.split("/")[4]);

        HttpSession session = req.getSession();

        if (session.getAttribute("user") == null) {
            RequestDispatcher bb = req.getRequestDispatcher("login.jsp");
            bb.forward(req, resp);
            return;
        }

        User user = this.repository.getUserById(id);

        if (user != null) {
            req.setAttribute("id", user.getId());
            req.setAttribute("fullName", user.getFullName());
            req.setAttribute("email", user.getEmail());
            req.setAttribute("age", user.getAge());
            req.setAttribute("password", user.getPassword());

//            req
//                .getRequestDispatcher("/profilePage.jsp")
//                .forward(req, resp);
            RequestDispatcher bb = req.getRequestDispatcher("/profilePage.jsp");
            bb.forward(req, resp);
            return;
        }
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doGet(req, resp);
    }
}

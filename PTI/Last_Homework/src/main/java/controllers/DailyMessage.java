package controllers;

import models.User;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;
import java.io.IOException;

@WebServlet(urlPatterns = "/dailyMessage")
public class DailyMessage extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        Cookie cookie = new Cookie("seen_cookie", "yes");
        cookie.setMaxAge(60 * 60 * 24); // 24 hours
        resp.addCookie(cookie);

        HttpSession session = req.getSession();
        User userFromSession = (User)session.getAttribute("user");

        req.setAttribute("id", userFromSession.getId());
        req.setAttribute("fullName", userFromSession.getFullName());
        req.setAttribute("email", userFromSession.getEmail());
        req.setAttribute("age", userFromSession.getAge());
        req.setAttribute("password", userFromSession.getPassword());

        RequestDispatcher bb = req.getRequestDispatcher("profilePage.jsp");
        bb.forward(req, resp);
    }
}

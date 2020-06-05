package controllers;

import com.google.gson.Gson;
import models.Vegetable;
import models.Vegetables;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;

@WebServlet(urlPatterns = "/vegetables")
public class VegetablesServlet extends HttpServlet {
    private Vegetables repository;

    private Gson gson = new Gson();

    @Override
    public void init() throws ServletException {
        HashSet<Vegetable> vegetables = new HashSet<Vegetable>();
        vegetables.add(new Vegetable("Vegetable 1", 100, 1.0));
        vegetables.add(new Vegetable("Vegetable 2", 100, 2.0));
        vegetables.add(new Vegetable("Vegetable 3", 100, 3.0));

        this.repository = new Vegetables();
        this.repository.setVegetables(vegetables);

        XMLWorker.writer(repository);
    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.setAttribute("vegetables", this.repository);
        RequestDispatcher dispatcher = req.getRequestDispatcher("/vegetables.jsp");
        dispatcher.forward(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //Прочита текстовото съдържанието на заявката
        StringBuilder sb = new StringBuilder();
        String line;

        while ((line = req.getReader().readLine()) != null) {
            sb.append(line);
        }

        Vegetable vegetable = this.gson.fromJson(sb.toString(), Vegetable.class);

        //Връщане на резултата като json
        int count = this.repository.reduceVegetablesCount(vegetable);

        resp.setContentType("application/json;charset=UTF-8");
        PrintWriter printWriter = resp.getWriter();
        printWriter.print(gson.toJson(count));
        printWriter.flush();
    }
}

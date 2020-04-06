package classes;

import java.io.IOException;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet(urlPatterns = "/login")
public class Login extends HttpServlet {
    private static final long serialVersionUID = 1L;

    private String docType;

    private String title;

    private String format;

    public void init() throws ServletException
    {
        docType = "<!doctype html public \"-//w3c//dtd html 4.0 transitional//en\">\n";
        title = "Using POST Method to Read Form Data";
        format = "%s <html>\n<head><title>%s</title></head>\n<body >\n<h1 align=\"center\">%s</h1>\n<ul>\n<li><b>First Name</b>:%s\n<li><b>Last Name</b>:%s\n</ul>\n</body></html>";
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
    {
        response.setContentType("text/html");

        String username = request.getParameter("username");
        String password = request.getParameter("password");

        if(username.isEmpty() || password.isEmpty())
        {
            RequestDispatcher req = request.getRequestDispatcher("views/login/errors/requiredFields.jsp");
            req.include(request, response);
        }

        else
        {
            for (User user: Register.users) {
                if(user.getUsername().equals(username) &&  user.getPassword().equals(password) ) {
                    request.setAttribute("name", user.getName());
                    request.setAttribute("username", user.getUsername());
                    request.setAttribute("password", user.getPassword());
                    request.setAttribute("age", user.getAge());
                    request.setAttribute("email", user.getEmail());
                    request.setAttribute("id", user.getId());

//                    response.sendRedirect("views/profilePage/profilePage.jsp");
                    RequestDispatcher profile = request.getRequestDispatcher("views/profilePage/profilePage.jsp");
                    profile.forward(request, response);
                    return;
                }
            }

            RequestDispatcher bb = request.getRequestDispatcher("views/login/errors/invalidCredentials.jsp");
            bb.forward(request, response);
        }
    }
}
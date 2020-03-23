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

    public static Map<String, String> users;

    public void init() throws ServletException
    {
        users = new HashMap<String, String>();
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
    {
        String firstName = request.getParameter("firstName");
        String username = request.getParameter("username");
        String password = request.getParameter("password");
        String confirmPassword = request.getParameter("confirmPassword");

        if (firstName.isEmpty() || username.isEmpty() || password.isEmpty() || confirmPassword.isEmpty())
        {
            RequestDispatcher req = request.getRequestDispatcher("views/register/errors/requiredFields.jsp");
            req.include(request, response);
        }

		if (!password.equals(confirmPassword))
		{
			RequestDispatcher req = request.getRequestDispatcher("views/register/errors/equalPasswords.jsp");
			req.forward(request, response);
		}

		if (!firstName.isEmpty() && !username.isEmpty() && !password.isEmpty() && !confirmPassword.isEmpty())
		{
		    if (this.users.containsKey(username))
		    {
                RequestDispatcher req = request.getRequestDispatcher("views/register/errors/usernameExists.jsp");
                req.include(request, response);
                return;
            }

			users.put(username, password);

			RequestDispatcher req = request.getRequestDispatcher("views/register/successfulRegistration.jsp");
			req.forward(request, response);
		}
    }

}
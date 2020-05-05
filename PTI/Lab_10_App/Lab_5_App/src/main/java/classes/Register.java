package classes;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

import java.io.File;
import java.io.IOException;
import java.util.*;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;

@WebServlet(urlPatterns = "/register")
public class Register extends HttpServlet {
    private static final long serialVersionUID = 1L;

    public static ArrayList<User> users;

    public void init() throws ServletException
    {
        users = new ArrayList<User>();
        try
        {
            String currentDirectory = this.getClass().getClassLoader().getResource("").getPath();
            //creating a constructor of file class and parsing an XML file
            File file = new File(currentDirectory + "/data.xml");
            //an instance of factory that gives a document builder
            DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
            //an instance of builder to parse the specified xml file
            DocumentBuilder db = dbf.newDocumentBuilder();
            Document doc = db.parse(file);
            doc.getDocumentElement().normalize();
            System.out.println("Root element: " + doc.getDocumentElement().getNodeName());
            NodeList nodeList = doc.getElementsByTagName("user");
            // nodeList is not iterable, so we are using for loop
            for (int itr = 0; itr < nodeList.getLength(); itr++)
            {
                Node node = nodeList.item(itr);
                System.out.println("\nNode Name :" + node.getNodeName());
                if (node.getNodeType() == Node.ELEMENT_NODE)
                {
                    Element eElement = (Element) node;
                    User user = new User(eElement.getElementsByTagName("username").item(0).getTextContent(),
                    eElement.getElementsByTagName("password").item(0).getTextContent(),  eElement.getElementsByTagName("password").item(0).getTextContent(), itr );
                    Register.users.add(user);
                }
            }
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        if(session.getAttribute("user") == null) {
            RequestDispatcher bb = request.getRequestDispatcher("register.jsp");
            bb.forward(request, response);
        }
        else {
            User userFromSession = (User)session.getAttribute("user");

            request.setAttribute("username", userFromSession.getUsername());
            request.setAttribute("name", userFromSession.getName());
            request.setAttribute("password", userFromSession.getPassword());
            request.setAttribute("age", userFromSession.getAge());
            request.setAttribute("email", userFromSession.getEmail());
            request.setAttribute("id", userFromSession.getId());

            RequestDispatcher profile = request.getRequestDispatcher("views/profilePage/profilePage.jsp");
            profile.forward(request, response);
        }
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
            req.include(request, response);
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

            try
            {
                String currentDirectory = this.getClass().getClassLoader().getResource("").getPath();
                //creating a constructor of file class and parsing an XML file
                File file = new File(currentDirectory + "/data.xml");
                //an instance of factory that gives a document builder
                DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
                //an instance of builder to parse the specified xml file
                DocumentBuilder db = dbf.newDocumentBuilder();
                Document doc = db.parse(file);
                Element dataTag = doc.getDocumentElement();
                Element listTag = (Element) dataTag.getElementsByTagName("list").item(0);
                Element user = doc.createElement("user");
                Element nameElem = doc.createElement("name");
                Element usernameElem = doc.createElement("username");
                Element passwordElem = doc.createElement("password");
                nameElem.setTextContent(firstName);
                usernameElem.setTextContent(username);
                passwordElem.setTextContent(password);
                user.appendChild(nameElem);
                user.appendChild(usernameElem);
                user.appendChild(passwordElem);
                listTag.appendChild(user);
                // output DOM XML to console
                // write the content into xml file
                TransformerFactory transformerFactory = TransformerFactory.newInstance();
                Transformer transformer = transformerFactory.newTransformer();
                DOMSource source = new DOMSource(doc);
                StreamResult result = new StreamResult(new File(currentDirectory + "/data.xml"));
                transformer.transform(source, result);
            }
            catch (Exception e)
            {
                e.printStackTrace();
            }
            response.sendRedirect("./login.jsp");
        }

//            request.setAttribute("name", firstName);
//            request.setAttribute("username", username);
//            request.setAttribute("password", password);
//            response.sendRedirect("./login.jsp");
    }
}
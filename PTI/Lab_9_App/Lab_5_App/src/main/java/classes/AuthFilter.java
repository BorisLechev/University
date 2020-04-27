package classes;

import javax.servlet.*;
import javax.servlet.annotation.WebFilter;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

@WebFilter(urlPatterns = "/profile/*")
public class AuthFilter implements Filter {

    public AuthFilter() {
    }

    public void destroy() {
    }

    public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain) throws IOException, ServletException {
        HttpSession session=((HttpServletRequest) request).getSession();

        if (session.getAttribute("user") == null) {
            HttpServletResponse httpResponse = (HttpServletResponse) response;
            httpResponse.sendRedirect("login");
        }
        else {
            chain.doFilter(request, response); // pass the request along the filter chain
        }
    }

    public void init(FilterConfig fConfig) throws ServletException {
    }
}

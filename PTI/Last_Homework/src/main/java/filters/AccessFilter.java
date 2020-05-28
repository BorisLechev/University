package filters;

import models.User;

import javax.servlet.*;
import javax.servlet.annotation.WebFilter;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

@WebFilter(urlPatterns = { "/edit/*" })
public class AccessFilter implements Filter {
    @Override
    public void init(FilterConfig filterConfig) throws ServletException {
    }

    @Override
    public void doFilter(ServletRequest servletRequest, ServletResponse servletResponse, FilterChain filterChain) throws IOException, ServletException {
        HttpServletRequest request = (HttpServletRequest) servletRequest;
        HttpServletResponse response = (HttpServletResponse) servletResponse;

        String url = request.getRequestURL().toString();
        int id = Integer.parseInt(url.split("/")[4]);

        HttpSession session = request.getSession();
        User user = (User)session.getAttribute("user");

        if (user.getId() == id) {
            filterChain.doFilter(servletRequest, servletResponse);
        } else {
            response.sendRedirect("/userslisting");
            return;
        }
    }

    @Override
    public void destroy() {
    }
}

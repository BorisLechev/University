package classes;


import javax.servlet.*;
import javax.servlet.annotation.WebFilter;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

@WebFilter(urlPatterns = "/edit/*")
public class EditProfileFilter implements Filter {

    public EditProfileFilter() {
    }

    public void destroy() {
    }

    public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain) throws IOException, ServletException {
        HttpSession session=((HttpServletRequest) request).getSession();
        String id = ((HttpServletRequest) request).getRequestURL().toString().split("/")[4];

        if (session.getAttribute("user_id").equals(id)) {
            chain.doFilter(request, response);
        }
        else {
            HttpServletResponse aa = (HttpServletResponse) response;
            aa.sendError(HttpServletResponse.SC_FORBIDDEN);
        }
    }

    public void init(FilterConfig fConfig) throws ServletException {
    }
}

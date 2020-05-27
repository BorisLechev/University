<%--
  Created by IntelliJ IDEA.
  User: Boris
  Date: 20.5.2020 г.
  Time: 16:52
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Login</title>
    <link rel="stylesheet" href="./css/login.css">
</head>
<body>
    <jsp:include page="navbar.jsp" />
    <div class="container">
        <form id="contact" action="login" method="post">
            <header>
                <h3 class="form-header">Login Form</h3>
            </header>
            <section class="input-box">
                <div for="email" class="label">Email</div>
                <input id="email" name="email" placeholder="Your email" type="email">
            </section>
            <section class="input-box">
                <div for="password" class="label">Password</div>
                <input id="password" name="password" placeholder="Your password should be at least 8 characters" type="password" required>
            </section>
            <section>
                <button name="submit" type="submit" id="contact-submit">Submit</button>
            </section>
            <a href="register.jsp"><b> To Registration form</b></a>
        </form>
    </div>
    <jsp:include page="footer.jsp" />
</body>
</html>

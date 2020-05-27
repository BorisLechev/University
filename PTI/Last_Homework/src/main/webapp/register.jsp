<%--
  Created by IntelliJ IDEA.
  User: Boris
  Date: 20.5.2020 г.
  Time: 16:53
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <link rel="stylesheet" href="./css/register.css">
    <title>Register</title>
</head>
<body>
    <jsp:include page="navbar.jsp" />
    <div class="container">
        <form id="contact" action="register" method="post">
            <header>
                <h3 class="form-header">Register Form</h3>
            </header>
            <section class="input-box">
                <div for="fullName" class="label">Full Name</div>
                <input id="fullName" name="fullName" placeholder="Your name" type="text" autofocus>
            </section>
            <section class="input-box">
                <div for="email" class="label">Email</div>
                <input id="email" name="email" placeholder="Your email" type="email">
            </section>
            <section class="input-box">
                <div for="password" class="label">Password</div>
                <input id="password" name="password" placeholder="Your password should be at least 8 characters" type="password">
            </section>
            <section class="input-box">
                <div for="confirm-password" class="label">Confirm Password</div>
                <input id="confirm-password" name="confirmPassword" placeholder="Your password should be at least 8 characters" type="password">
            </section>
            <section>
                <button name="submit" type="submit" id="contact-submit">Submit</button>
            </section>
            <a href="login.jsp"><b> To Login form</b></a>
        </form>

        <jsp:include page="footer.jsp" />
    </div>
</body>
</html>

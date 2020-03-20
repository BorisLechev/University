<%--
  Created by IntelliJ IDEA.
  User: Boris
  Date: 18.3.2020 г.
  Time: 16:57
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="/css/login.css">
    <title>Login</title>
</head>
<body>
<div class="container">
    <form id="contact" action="/login" method="post">
        <header>
            <h3 class="form-header">Login Form</h3>
        </header>
        <section class="input-box">
            <div for="username" class="label">Username</div>
            <input id="username" placeholder="Your Username" type="text" required>
        </section>
        <section class="input-box">
            <div for="password" class="label">Password</div>
            <input id="password" placeholder="Your password should be at least 8 characters" type="password" required>
        </section>
        <section>
            <button name="submit" type="submit" id="contact-submit" data-submit="...Sending">Submit</button>
        </section>
    </form>
</div>
</body>
</html>

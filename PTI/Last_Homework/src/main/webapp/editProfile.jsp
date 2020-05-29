<%--
  Created by IntelliJ IDEA.
  User: Boris
  Date: 22.5.2020 г.
  Time: 9:59
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<% String id = request.getAttribute("id").toString(); %>
<% String fullName = request.getAttribute("fullName").toString(); %>
<% String password = request.getAttribute("password").toString(); %>
<% Integer age = Integer.parseInt(request.getAttribute("age").toString()); %>
<% String email = request.getAttribute("email").toString(); %>

<html>
<head>
    <title>Edit</title>
    <link rel="stylesheet" href="./css/login.css">
    <script src="https://code.jquery.com/jquery-3.5.0.min.js"></script>
</head>
<body>
<jsp:include page="navbar.jsp" />
<div class="container">
    <form id="contact" action="/edit/<%=id%>" method="post">
        <header>
            <h3 class="form-header">Edit Profile</h3>
            <h4>Main Information</h4>
        </header>
        <section class="input-box">
            <div for="fullName" class="label">Full Name</div>
            <input id="fullName" name="fullName" type="text" value = "<%=fullName%>" required>
        </section>
        <section class="input-box">
            <div for="password" class="label">Password</div>
            <input id="password" name="password" value = "<%=password%>" type="password" required>
        </section>
        <section>
            <button id="submit1" name="submit" type="submit">Submit</button>
        </section>
        <input type="hidden" name="id" value = "<%=id%>">
    </form>

    <form action="/edit/<%=id%>" method="post">
        <header>
            <h4 class="form-header">Additional Information</h4>
        </header>
        <section class="input-box">
            <div for="age" class="label">Age</div>
            <input id="age" name="age" type="number" value = "<%=age%>" required>
        </section>
        <section class="input-box">
            <div for="email" class="label">Email</div>
            <input id="email" name="email" type="email" value = "<%=email%>" required>
        </section>
        <section>
            <button name="submit" type="submit">Submit</button>
        </section>
        <input type="hidden" name="id" value = "<%=id%>">
        <a href="/profile/<%=id%>"><b> To Profile page</b></a>
    </form>

    <h3 id="message"></h3>
</div>
<script>
    $(document).ready(function () {
        const message = $("#message");
        $('form').submit(async function(e) {
            e.preventDefault();
            let form = $(this);
            await $.post(form.attr('action'), form.serialize())
                .done(function() {
                    alert('success');
                    message.html("Saved.");
                })
                .fail(function() {
                    alert('fail');
                    message.html("Something went wrong.");
                });
        });
    });
</script>
</body>
</html>

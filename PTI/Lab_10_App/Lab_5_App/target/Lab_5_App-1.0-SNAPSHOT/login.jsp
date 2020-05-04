<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="./css/login.css">
    <title>Login</title>
</head>
<body>
    <jsp:include page="navbar.jsp" />
    <div class="container">
        <form id="contact" action="login" method="post">
            <header>
                <h3 class="form-header">Login Form</h3>
            </header>
            <section class="input-box">
                <div for="username" class="label">Username</div>
                <input id="username" name="username" placeholder="Your Username" type="text" required>
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
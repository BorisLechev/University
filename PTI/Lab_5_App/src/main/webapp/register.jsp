<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="./css/register.css">
    <title>Register</title>
</head>
<body>
<div class="container">
    <form id="contact" action="register" method="post">
        <header>
            <h3 class="form-header">Register Form</h3>
        </header>
        <section class="input-box">
            <div for="name" class="label">Name</div>
            <input id="name" name="firstName" placeholder="Your name" type="text" autofocus>
        </section>
        <section class="input-box">
            <div for="username" class="label">Username</div>
            <input id="username" name="username" placeholder="Your Username" type="text">
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
</div>
</body>
</html>
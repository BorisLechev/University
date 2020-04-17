<%--
  Created by IntelliJ IDEA.
  User: Boris
  Date: 16.4.2020 г.
  Time: 8:46
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<!DOCTYPE html>
<html>
<head>
    <meta charset="ISO-8859-1">
    <title>Users</title>
    <link rel="stylesheet" href="./css/list-users.css">
</head>
<body>
    <jsp:include page="navbar.jsp" />
    <main class="row">
        <section class="inner-row">
            <section class="table-responsive">
                <table class="table table-hover">
                    <thead>
                    <tr>
                        <th>Name</th>
                        <th>Username</th>
                        <th></th>
                    </tr>
                    </thead>
                    <tbody>
                        <c:forEach items="${users}" var="user">
                        <tr>
                            <td>${user.getName()}</td>
                            <td>${user.getUsername()}</td>
                            <td><a href="profile/${user.getId()}">Check Profile</a></td>
                        </tr>
                        </c:forEach>
                    </tbody>
                </table>
            </section>
        </section>
    </main>
    <jsp:include page="footer.jsp" />
</body>
</html>

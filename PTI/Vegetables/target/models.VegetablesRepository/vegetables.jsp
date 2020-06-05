<%@ page import="java.util.HashSet" %><%--
  Created by IntelliJ IDEA.
  User: Boris
  Date: 4.6.2020 г.
  Time: 21:40
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ page import="models.Vegetable" %>
<jsp:useBean id="vegetables" type="models.VegetablesRepository" scope="request"></jsp:useBean>
<html>
<head>
    <title>models.VegetablesRepository list</title>
    <script type="text/javascript" src="js/site.js"></script>
</head>
<body>
    <header>
        <h1>models.VegetablesRepository list</h1>
    </header>
    <main>
        <table>
            <thead>
                <tr>
                    <th>Name</th>
                    <th>Count</th>
                    <th>Price</th>
                    <th>Action</th>
                </tr>
            </thead>
            <tbody>
                <% for (Vegetable vegetable : vegetables.getVegetables()) { %>
                    <tr>
                        <td><%=vegetable.getName()%></td>
                        <td id="<%=vegetable.getName()%>"><%=vegetable.getCount()%></td>
                        <td><%=vegetable.getPrice()%></td>
                        <td><button type="button" onclick="reduceVegetables('<%=vegetable.getName()%>')">Reduce</button></td>
                    </tr>
                 <% } %>
            </tbody>
        </table>
    </main>
</body>
</html>
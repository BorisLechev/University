<%@ page import="models.User" %><%--
  Created by IntelliJ IDEA.
  User: Boris
  Date: 20.5.2020 г.
  Time: 22:04
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<% String fullName = request.getAttribute("fullName").toString(); %>
<% Integer age = Integer.parseInt(request.getAttribute("age").toString()); %>
<% String email = request.getAttribute("email").toString(); %>
<% int id = Integer.parseInt(request.getAttribute("id").toString()); %>

<%
    HttpSession s = request.getSession();
    User user = (User)s.getAttribute("user");
%>

<%--<jsp:useBean id = 'students' class = 'models.User'>--%>
<%--    <jsp:setProperty name = "students" property = "fullName" value="<%=fullName%>"/>--%>
<%--    <jsp:setProperty name = "students" property = "password" value="<%=password%>"/>--%>
<%--    <jsp:setProperty name = "students" property = "email" value="<%=email%>"/>--%>
<%--    <jsp:setProperty name = "students" property = "age" value="<%=age%>"/>--%>
<%--</jsp:useBean>--%>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link rel="stylesheet" href="./css/profilePage.css">
</head>
<body>
    <jsp:include page="./navbar.jsp" />
    <header class="site-header"></header>
    <main class="main">
        <section class="picture-container">
            <img src="./images/male.svg" alt="pic">
        </section>
        <section class="info-container">
            <header>
                <h3>Профилна информация</h3>
            </header>
            <main>
                <p>Име: <%=fullName%></p>
                <p>Възраст: <%=age%></p>
                <p>Работа: Студент</p>
                <p>Описание: Lorem ipsum dolor sit amet consectetur, adipisicing elit. Temporibus labore, dolore nulla consequuntur quia voluptate inventore. Vitae itaque similique odio mollitia nisi aliquid architecto expedita quaerat sequi optio! Praesentium, nostrum? Lorem ipsum dolor sit amet consectetur adipisicing elit. Consectetur rerum, autem libero laudantium dolorum quod obcaecati explicabo nisi? Nam totam quam sunt tempore ab qui aspernatur quas cum dolorem id.</p>
            </main>

            <%
                Boolean cookieSet = false;
                for(int i = 0; i < request.getCookies().length ; i++) {
                    if(request.getCookies()[i].getName().equals("seen_cookie")) {
                        cookieSet = true;
                    }
                }
            %>

            <% if(!cookieSet) { %>
                Welcome!
                <br>
                <a href="/dailyMessage">Stop Welcoming me</a>
            <% } %>

            <% if (user.getId() == id) { %>
                <a href="/edit/<%=id%>">Edit</a>
            <% } %>
        </section>
    </main>
    <section class="umenia-container">
        <article class="profesionalni">
            <header>
                <h3>Професионални</h3>
            </header>
            <main>
                <article>
                    <div class="name">Java</div>
                    <div class="diagram1"></div>
                    <div class="diagram2"></div>
                </article>
                <article>
                    <div class="name">HTML</div>
                    <div class="diagram1"></div>
                    <div class="diagram2"></div>
                </article>
                <article>
                    <div class="name">CSS</div>
                    <div class="diagram1"></div>
                    <div class="diagram2"></div>
                </article>
                <article>
                    <div class="name">JavaScript</div>
                    <div class="diagram1"></div>
                    <div class="diagram2"></div>
                </article>
            </main>
        </article>
        <article class="lichnostni">
            <header>
                <h3>Личностни</h3>
            </header>
            <main>
                <article>
                    <div class="name">Комуникативност</div>
                    <div class="diagram1"></div>
                    <div class="diagram2"></div>
                </article>
                <article>
                    <div class="name">Екипна работа</div>
                    <div class="diagram1"></div>
                    <div class="diagram2"></div>
                </article>
                <article>
                    <div class="name">Креативност</div>
                    <div class="diagram1"></div>
                    <div class="diagram2"></div>
                </article>
            </main>
        </article>
    </section>

    <section class="umenia-container">
        <article class="profesionalni">
            <main>
                <article>
                    <div class="name">Имейл</div>
                    <a href="#"><%=email%></a>
                </article>
                <article>
                    <div class="name">Телефон</div>
                    <div>54365465454</div>
                </article>
            </main>
        </article>
        <article class="lichnostni">
            <main>
                <article>
                    <div class="name">Град</div>
                    <div>Варна</div>
                </article>
                <article>
                    <div class="name">Улица</div>
                    <div>Студентска 1</div>
                </article>
            </main>
        </article>
    </section>
    <footer></footer>
</body>
</html>

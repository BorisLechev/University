package classes;

public class User implements java.io.Serializable {
    private static final long serialVersionUID = 1L;

    private int id;

    private String name = null;

    private String username = null;

    private String password = null;

    private String age = "";

    private String email = "";

    public User(String name, String username, String password, int id) {
        this.setName(name);
        this.setUsername(username);
        this.setPassword(password);
        this.setId(id);
    }

    public User() {

    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getAge() {
        return age;
    }

    public void setAge(String age) {
        this.age = age;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }
}
public class Person {
    private String Name;

    private int Age;

    public Person(String name, int age) {
        this.Name = name;
        this.Age = age;
    }

    public String getName() {
        return this.Name;
    }

    public void setName(String name) {
        this.Name = name;
    }

    public int getAge() {
        return this.Age;
    }

    public void setAge(int age) {
        this.Age = age;
    }

    public String toString() {
        return this.getName() + " - " + this.getAge();
    }
}

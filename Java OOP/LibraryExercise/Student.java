import java.util.GregorianCalendar;

public class Student extends Applicant implements Comparable {
    protected String FacultyNumber;

    // Constructors
    public Student(String name, String facultyNumber) {
        super(new GregorianCalendar(), name, 0.0);

        this.FacultyNumber = facultyNumber;
    }

    public Student(GregorianCalendar applicationDate, String name, double grade, String facultyNumber) {
        super(applicationDate, name, grade);

        this.FacultyNumber = facultyNumber;
    }

    public String getFacultyNumber() {
        return FacultyNumber;
    }

    public void setFacultyNumber(String facultyNumber) {
        this.FacultyNumber = facultyNumber;
    }

    public int compareTo(Object object) {
        return FacultyNumber.compareTo(((Student) object).getFacultyNumber());
    }

    public boolean equals(Student object) {
        return (FacultyNumber.compareTo(((Student) object).getFacultyNumber()) == 0);
    }

    public String toString() {
        return String.format("Faculty Number: %s, %s.", getFacultyNumber(), super.toString());
    }
}

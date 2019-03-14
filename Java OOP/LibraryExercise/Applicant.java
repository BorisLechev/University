import java.util.GregorianCalendar;

public class Applicant {
    private String Name;

    private GregorianCalendar ApplicationDate;

    private double Grade;

    // Constructor
    public Applicant(GregorianCalendar applicationDate, String name, double grade) {
        Name = name;
        ApplicationDate = applicationDate;
        Grade = grade;
    }

    // get/set
    public String getName() {
        return Name;
    }

    public void setName(String nameParam) {
        this.Name = nameParam;
    }

    public GregorianCalendar getApplicationDate() {
        return ApplicationDate;
    }

    public void setApplicationDate(GregorianCalendar applicationDateParam) {
        this.ApplicationDate = applicationDateParam;
    }

    public double getGrade() {
        return Grade;
    }

    public void setGrade(double gradeParam) {
        this.Grade = gradeParam;
    }

    public String toString() {
        return String.format("Student name: %s, Application date:  %s, Grade: %s.", Name, ApplicationDate, Grade);
    }
}

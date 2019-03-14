import java.util.GregorianCalendar;

public class Reader extends Student implements Comparable, ReaderInterface {
    private LibraryBookInterface ReaderBook;

    public void get(LibraryBookInterface book) {
        ReaderBook = book;
    }

    public void ret(LibraryBookInterface book) {
        book.ret();
        ReaderBook = null;
    }

    // Explicit Constructor
    public Reader(String name, GregorianCalendar applicationDate, double grade, String facultyNumber) {
        super(applicationDate, new String(name), grade, new String(facultyNumber));
    }

    public Reader(String name, String facultyNumber) {
        super(new String(name), new String(facultyNumber));
    }

    public LibraryBookInterface getReaderBook() {
        return ReaderBook;
    }

    public void setReaderBook(LibraryBookInterface readerBook) {
        this.ReaderBook = readerBook;
    }

    public int compareTo(Object object) {
        return FacultyNumber.compareTo(((Reader) object).FacultyNumber);
    }

    public boolean equals(Object object) {
        if (object.getClass().getName().compareTo(this.getClass().getName()) != 0) {
            return false;
        } else {
            Reader rd = (Reader) object;
            if (this.FacultyNumber.compareTo(rd.FacultyNumber) == 0) {
                return true;
            } else {
                return false;
            }
        }
    }

    public String toString() {
        return new String("Reader:" + super.getName() + "; Faculty number: " + FacultyNumber);
    }
}

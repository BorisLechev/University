public class LibraryBook implements Comparable {
    private Reader BookReader;

    private String BookName;

    private boolean Status;


    public String getBookName() {
        return new String(BookName);
    }

    public void setBookName(String name) {
        BookName = new String(name);
    }

    public boolean getBookStatus() {
        return Status;
    }

    public void setBookStatus(boolean status) {
        Status = status;
    }

    // Explicit Constructor
    public LibraryBook(String bookName, boolean status) {
        BookReader = new Reader("N/a", "N/a");
        BookName = new String(bookName);
        Status = status;
    }

    public void get(Reader reader) {
        BookReader.setName(reader.getName());
        BookReader.setFacultyNumber(reader.getFacultyNumber());
        Status = true;
    }

    public void ret(Reader reader) {
        BookReader.setName("N/A");
        BookReader.setFacultyNumber("N/A");
        Status = false;
    }

    public int compareTo(Object object) {
        LibraryBook libraryBook = (LibraryBook) object;

        return this.toString().compareTo(libraryBook.toString());
    }

    public boolean equals(Object object) {
        if (object.getClass().getName().compareTo(this.getClass().getName()) != 0) {
            return false;
        } else {
            LibraryBook libraryBook = (LibraryBook) object;
            if (this.toString().compareTo(libraryBook.toString()) == 0) {
                return true;
            } else {
                return false;
            }
        }
    }

    public String toString() {
        return new String("Book:" + BookName + "; Status: " + Status + ";");
    }
}

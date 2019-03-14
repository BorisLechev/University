import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        LibraryBook[] libraryBook = new LibraryBook[2];
        {
            // LibraryBook.java -> constructor Reader.java -> Reader constructor Student -> Student Applicant
            LibraryBook firstBook = new LibraryBook("Pod Igoto", false);
            LibraryBook secondBook = new LibraryBook("Tutun", false);

            libraryBook[1] = firstBook;
            libraryBook[1].get((Reader) new Reader("John", "123456"));// (Reader) зариди ret() 23 red
            libraryBook[0] = secondBook;
            libraryBook[0].get((Reader) new Reader("Yordan", "1239999"));
        }

        System.out.println(" All: " + Arrays.toString(libraryBook));

        Arrays.sort(libraryBook);
        System.out.println("All sorted: " + Arrays.toString(libraryBook));

        // return the book -print
        // libraryBook[0].ret();
        System.out.println(" Second Book: " + libraryBook[0]);

        // are they equivalent
        if (libraryBook[0].compareTo(libraryBook[1]) == 0) {
            System.out.println(libraryBook[0] + " Equals " + libraryBook[1]);
        } else {
            System.out.println(libraryBook[0] + " Not Equal to " + libraryBook[1]);
        }

        //print array
        System.out.println(" ALL " + Arrays.toString(libraryBook));
    }
}

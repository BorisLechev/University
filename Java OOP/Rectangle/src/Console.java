public class Console {
    public static void printPrompt(String prompt) {
        System.out.print(prompt + " ");
        System.out.flush();
    }

    public static String readLine() {
        int ch;
        String r = "";
        boolean done = false;
        while (!done) {
            try {
                ch = System.in.read();
                if ((char) ch == '\n') done = true;
                else if (ch != '\r') r = r + (char) ch;
            }
            catch(java.io.IOException e) {
                done = true;
            }
        }
        return r;
    }

    public static String readLine(String prompt) {
        printPrompt(prompt);
        return readLine();
    }

    public static int readInt(String prompt) {
        while(true) {
            printPrompt(prompt);
            try {
                return Integer.parseInt(readLine().trim());
            }
            catch(NumberFormatException e)  {
                System.out.println("Not an integer. Please try again!");
            }
        }
    }

    public static long readLong(String prompt) {
        while(true) {
            printPrompt(prompt);
            try {
                return Long.parseLong(readLine().trim());
            }
            catch(NumberFormatException e)  {
                System.out.println("Not an long. Please try again!");
            }
        }
    }

    public static double readDouble(String prompt) {
        while(true) {
            printPrompt(prompt);
            try {
                return Double.parseDouble(readLine().trim());
            }
            catch(NumberFormatException e) {
                System.out.println("Not a floating point number. Please try again!");
            }
        }
    }
}
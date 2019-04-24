import java.io.EOFException;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.Arrays;

public class RectangleArray {
    private ColorRectangle[] oColl;

    //експлицитен конструктор
    public RectangleArray(String fileName) {
        try {
            RandomAccessFile myFile = new RandomAccessFile(fileName, "r");

            String[] res = new String[5];
            String strLine;
            oColl = new ColorRectangle[10];
            int i = 0;

            while ((strLine = myFile.readLine()) != null &&
                    strLine.length() > 0) {
                res = strLine.split(" ");
                Integer oIntX1 = Integer.valueOf(res[0]);
                Integer oIntY1 = Integer.valueOf(res[1]);
                Integer oIntX2 = Integer.valueOf(res[2]);
                Integer oIntY2 = Integer.valueOf(res[3]);
                Integer oColor = Integer.valueOf(res[4]);
                ColorRectangle oRectangle = new ColorRectangle(oIntX1, oIntY1, oIntX2, oIntY2, oColor);

                if (i == oColl.length) {
                    break;
                }

                oColl[i++] = oRectangle;
            }

            myFile.close();
        } catch (FileNotFoundException e) {
            System.out.println("File Not Found ...");
        } catch (EOFException e) {
            System.out.println("End of file encountered ...");
        } catch (IOException e) {
            System.out.println("Input/Output Error ....");
        }
    }

    public void printColl() {
        System.out.println(Arrays.toString(oColl));
    }

    public void sortColl() {
        Arrays.sort(oColl);
    }

    public double calcSumArea() {
        double sum = 0.;

        for (int i = 0; i < oColl.length; i++) {
            if (oColl[i] != null) {
                sum += oColl[i].area();
            }
        }

        return sum;
    }

    public double calcSumPerimeter() {
        double sum = 0.;

        for (int i = 0; i < oColl.length; i++) {
            if (oColl[i] != null) {
//				 sum += oColl[i].perimeter();
            }
        }

        return sum;
    }

    public static void main(String[] args) {
        RectangleArray obj = new RectangleArray(".\\ColorRects.txt");
        obj.printColl();
        obj.sortColl();
        obj.printColl();
        System.out.println("Sum Area : " + obj.calcSumArea());
        System.out.println("Sum Perim : " + obj.calcSumPerimeter());
    }
}
import java.io.EOFException;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.*;

public class RectangleCollection {
    public SortedSet<ColorRectangle> collection;

    // Подразбиращ се конструктор
    public RectangleCollection() {
        collection = new TreeSet<ColorRectangle>();
    }

    public RectangleCollection(String fileName) throws IOException {
        try {
            RandomAccessFile file = new RandomAccessFile(fileName, "r");

            String[] inputRows = new String[4];
            String currentRow;
            collection = new TreeSet<ColorRectangle>(); ////////////////

            while ((currentRow = file.readLine()) != null && currentRow.length() > 0) {
                inputRows = currentRow.split(" ");

                int firstElement = Integer.parseInt(inputRows[0]); // element of each row
                int secondElement = Integer.parseInt(inputRows[1]); // element of each row
                int thirdElement = Integer.parseInt(inputRows[2]); // element of each row
                int fourthElement = Integer.parseInt(inputRows[3]); // element of each row

                ColorRectangle currentRectangle = new ColorRectangle(
                        firstElement,
                        secondElement,
                        thirdElement,
                        fourthElement
                );

                collection.add(currentRectangle);
            }

            file.close();
        } catch (FileNotFoundException e) {
            System.out.println("File Not Found ...");
        } catch (EOFException e) {
            System.out.println("End of file encountered ...");
        } catch (IOException e) {
            System.out.println("Input/Output Error ....");
        }
    }

    // добавя само ако не се повтаря (понеже е TreeSet)
    public boolean addRectangle(ColorRectangle rectangle) {
        return collection.add(rectangle);
    }

    public ColorRectangle calcUnionColl() {
        ColorRectangle result = new ColorRectangle(0, 0, 0, 0);

        // във FOR няма стъпка, защото обхождането става с Iterator
        for (Iterator<ColorRectangle> i = collection.iterator(); i.hasNext(); ) {
            ColorRectangle current = (ColorRectangle) i.next();
            result = result.unionRect(current);
        }

        return result;
    }

    // Изчислява минимален по площ правоъгълник:ColorRectangle
    public ColorRectangle calcMin() {
        ColorRectangle result = new ColorRectangle(1000, 1000, 1000, 1000);//default min
        Iterator<ColorRectangle> iterator = collection.iterator();

        if (iterator.hasNext()) {
            result = (ColorRectangle) collection.last();
        }

        return result;
    }

    // Изчислява максималния по площ правоъгълник:ColorRectangle
    public ColorRectangle calcMax() {
        ColorRectangle result = new ColorRectangle(-1000, -1000, -1000, -1000);//default
        Iterator<ColorRectangle> iterator = collection.iterator();

        if (iterator.hasNext()) {
            result = (ColorRectangle) collection.last();
        }

        return result;
    }

    // Изчислява /връща броя на припокритите от някой друг правоъгълник правоъгълници
    private int counter(ColorRectangle rectangle) {
        int count = 0;
        Iterator<ColorRectangle> iterator = collection.iterator();
        ColorRectangle currentRectangle = new ColorRectangle();

        while (iterator.hasNext()) {
            currentRectangle = (ColorRectangle) iterator.next();

            if (rectangle != currentRectangle &&
                    (rectangle.getIX1() >= currentRectangle.getIX1()) &&
                    (rectangle.getIX2() <= currentRectangle.getIX2()) &&
                    (rectangle.getIY1() >= currentRectangle.getIY1()) &&
                    (rectangle.getIY2() <= currentRectangle.getIY2())) {
                count++;
                break;
            }
        }

        return count;
    }

    public int countNesting() {
        int allNested = 0;

        for (ColorRectangle currentRectangle : collection) {
            allNested += counter(currentRectangle);
        }

        return allNested;
    }

    // Връща броя елементи в множеството
    public int getSetSize() {
        return collection.size();
    }

    public void printCollection(Collection<ColorRectangle> collection) {
        for (Iterator<ColorRectangle> i = collection.iterator(); i.hasNext(); ) {
            System.out.println(i.next().toString());
        }
    }

    public double calcSumArea() {
        double sum = 0.;

        Iterator<ColorRectangle> iterator = collection.iterator();

        while (iterator.hasNext()) {
            sum += ((ColorRectangle) iterator.next()).area();
        }

        return sum;
    }

    public double calcSumPerimeter() {
        double sum = 0.;

        Iterator<ColorRectangle> iterator = collection.iterator();

        while (iterator.hasNext()) {
            sum += ((ColorRectangle) iterator.next()).perimeter();
        }
        return sum;
    }

    public List<ColorRectangle> reverseList() {
        List<ColorRectangle> lst = new ArrayList<ColorRectangle>(collection);
        List<ColorRectangle> lstResult = new ArrayList<ColorRectangle>();

        for (ListIterator<ColorRectangle> iterator = lst.listIterator(lst.size()); iterator.hasPrevious(); ) {
            ColorRectangle prev = (ColorRectangle) iterator.previous();
            lstResult.add(prev);
        }

        return lstResult;
    }

    public boolean findRect(ColorRectangle toFind) {
        return collection.contains(toFind);
    }

    public static void main(String[] args) throws IOException {
        RectangleCollection obj = new RectangleCollection("rects.txt");
        obj.addRectangle(new ColorRectangle(2, 2, 400, 400));
//	obj.addRectangle(new ColorRectangle(-1, -1, 10, 6));//Повтарящ се елемент и не се добавя
        obj.printCollection(obj.collection);
        System.out.println("\n\r");
        System.out.println("Union Result:" + obj.calcUnionColl());
        System.out.println("Min Result:" + obj.calcMin());
        System.out.println("Max Result:" + obj.calcMax());
        System.out.println("Reverse:" + obj.reverseList());
        System.out.println("Sum Area:" + obj.calcSumArea());
        System.out.println("Sum Perimeter:" + obj.calcSumPerimeter());
        System.out.println("Size:" + obj.getSetSize());
        System.out.println("Nesting:" + obj.countNesting());
    }
}

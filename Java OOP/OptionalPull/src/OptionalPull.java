import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.TreeSet;

public class OptionalPull {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        TreeSet<String> people = new TreeSet<>();

        int countOfLines = Integer.parseInt(reader.readLine());

        for (int i = 0; i < countOfLines; i++) {
            String[] input = reader.readLine().split(" ");

            String name = input[0];
            int age = Integer.parseInt(input[1]);

            Person currentPerson = new Person(name, age);

            if (currentPerson.getAge() > 30) {
                people.add(currentPerson.toString());
            }
        }

        people.stream()
                .sorted()
                .forEach(person -> System.out.println(person.toString()));
    }
}

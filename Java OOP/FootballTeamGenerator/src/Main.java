import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner console = new Scanner(System.in);

        String input = console.nextLine();

        String[] segments = input.split(";");
        Team team = new Team();
        team.SetName(segments[1]);

        input = console.nextLine();

        while (!input.equals("END")) {
            segments = input.split(";");

            String command = segments[0];
            String teamName = segments[1];

            if (command.equals("Add")) {
                String playerName = segments[2];

                Player player = new Player();
                player.SetName(playerName);

                int endurance = Integer.parseInt(segments[3]);
                int sprint = Integer.parseInt(segments[4]);
                int dribble = Integer.parseInt(segments[5]);
                int passing = Integer.parseInt(segments[6]);
                int shooting = Integer.parseInt(segments[7]);

                player.SetEndurance(endurance);
                player.SetSprint(sprint);
                player.SetDribble(dribble);
                player.SetPassing(passing);
                player.SetShooting(shooting);

                team.AddPlayer(player);
            }

            if (command.equals("Remove")) {
                String playerName = segments[2];

                team.RemovePlayer(playerName);
            }

            if (command.equals("Rating")) {
                System.out.println(team.GetName() + " - " + Math.floor(team.Rating()));
            }

            input = console.nextLine();
        }
    }
}
import java.util.ArrayList;
import java.util.List;

public class Team {
    private List<Player> Players;
    private String Name;

    Team() {
        this.Players = new ArrayList<Player>();
    }

    public String GetName() {
        return this.Name;
    }

    public void SetName(String name) {
        this.Name = name;
    }

    public double Rating() {
        double sumOfOverallSkills = 0;

        for (int i = 0; i < Players.size(); i++) {
            Player player = Players.get(i);
            sumOfOverallSkills += player.overallSkill();
        }

        if (Players.size() == 0) {
            return 0;
        }

        return sumOfOverallSkills / Players.size();
    }

    public void AddPlayer(Player player) {
        this.Players.add(player);
    }

    public void RemovePlayer(String name) {
//        if (!this.Players.contains(player)) {
//            System.out.println("Player" + player.GetName() + "is not in" + this.GetName() + "team.");
//        } else {
//            this.Players.remove(player);
//        }
        boolean isFound = false;

        for (int i = 0; i < Players.size(); i++) {
            Player player = Players.get(i);

            if (player.GetName() == player.GetName()) {
                Players.remove(i);
                isFound = true;
            }
        }

        if (!isFound) {
            System.out.println("Player" + name + "is not in" + this.GetName() + "team.");
        }
    }
}
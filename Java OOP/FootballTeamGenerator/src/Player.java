public class Player {
    private String Name;
    private int Endurance;
    private int Sprint;
    private int Dribble;
    private int Passing;
    private int Shooting;

    public String GetName() {
        return this.Name;
    }

    public void SetName(String name) {
        if (name == null || name == "" || name == " ") {
            System.out.println("A name should not be empty.");
        } else {
            this.Name = name;
        }
    }

    public int GetEndurance() {
        return this.Endurance;
    }

    public void SetEndurance(int endurance) {
        if (endurance < 0 || endurance > 100) {
            System.out.println("Endurance should be between 0 and 100.");
        } else {
            this.Endurance = endurance;
        }
    }

    public int GetSprint() {
        return this.Sprint;
    }

    public void SetSprint(int sprint) {
        if (sprint < 0 || sprint > 100) {
            System.out.println("Sprint should be between 0 and 100.");
        } else {
            this.Sprint = sprint;
        }
    }

    public int GetDribble() {
        return this.Dribble;
    }

    public void SetDribble(int dribble) {
        if (dribble < 0 || dribble > 100) {
            System.out.println("Dribble should be between 0 and 100.");
        } else {
            this.Dribble = dribble;
        }
    }

    public int GetPassing() {
        return this.Passing;
    }

    public void SetPassing(int passing) {
        if (passing < 0 || passing > 100) {
            System.out.println("Passing should be between 0 and 100.");
        } else {
            this.Passing = passing;
        }
    }

    public int GetShooting() {
        return this.Shooting;
    }

    public void SetShooting(int shooting) {
        if (shooting < 0 || shooting > 100) {
            System.out.println("Shooting should be between 0 and 100.");
        } else {
            this.Shooting = shooting;
        }
    }

    public double overallSkill() {
        return (this.Endurance + this.Sprint + this.Dribble + this.Passing + this.Shooting) / 5;
    }
}
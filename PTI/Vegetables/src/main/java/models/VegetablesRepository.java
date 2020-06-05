package models;

import java.util.HashSet;

public class VegetablesRepository {
    private static VegetablesRepository repository;

    private HashSet<Vegetable> vegetables;

    public VegetablesRepository() {
        this.vegetables = new HashSet<Vegetable>();
    }

    public static VegetablesRepository getInstance() {
        if (repository == null) {
            repository = new VegetablesRepository();
        }

        return repository;
    }

    public HashSet<Vegetable> getVegetables() {
        return this.vegetables;
    }

    public void setVegetables(HashSet<Vegetable> vegetables) {
        this.vegetables = vegetables;
    }

    public void addVegetable(Vegetable vegetable) {
        this.vegetables.add(vegetable);
    }

    public int reduceVegetablesCount(Vegetable vegetable) {
        for (Vegetable currentVegetable : this.vegetables) {
            if (currentVegetable.equals(vegetable)) {
                int currentVegetableCount = currentVegetable.getCount();
                int vegetableCount = vegetable.getCount();

                if (currentVegetableCount > vegetableCount) {
                    currentVegetableCount -= vegetableCount;
                    currentVegetable.setCount(currentVegetableCount);
                } else {
                    currentVegetableCount = 0;
                    currentVegetable.setCount(currentVegetableCount);
                }

                return currentVegetableCount;
            }
        }

        return 0;
    }
}

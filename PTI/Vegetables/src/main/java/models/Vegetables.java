package models;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlRootElement;
import java.util.HashSet;

@XmlRootElement(name = "vegetables")
@XmlAccessorType(XmlAccessType.FIELD)
public class Vegetables {
    @XmlElement(name = "vegetable")
    private HashSet<Vegetable> vegetables;

    public Vegetables() {
        this.vegetables = new HashSet<Vegetable>();
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

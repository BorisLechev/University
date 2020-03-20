package models.entity;

import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.MappedSuperclass;

@MappedSuperclass
public class BaseEntity {
    private int id;

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }


//    Za HashSet
//    @Override
//    public boolean equals(Object obj) {
//        if (obj == null || !(obj instanceof BaseEntity)) {
//            return false;
//        }
//
//        return equals((BaseEntity)obj);
//    }
//
//    @Override
//    public int hashCode() {
//        return getId();
//    }
//
//    public boolean equals(BaseEntity obj) {
//        return getId() == obj.getId();
//    }
}

package models;

import xml.XMLWorker;

import javax.xml.bind.JAXBException;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlElementWrapper;
import java.io.FileNotFoundException;
import java.util.HashSet;

public class UserRepository {
    private static UserRepository repository;

    private final String xmlFilePath  = "C:\\Users\\Boris\\Desktop\\Java_Projects\\Last_Homework\\src\\main\\webapp\\xml\\users.xml";

    @XmlElementWrapper(name = "users")
    @XmlElement(name = "user")
    private HashSet<User> users = new HashSet<User>();

    private UserRepository() {
        XMLWorker worker = new XMLWorker();

        try {
            UsersListXML repository = worker.readerFromXMLFile(this.xmlFilePath);
            this.users.addAll(repository.getUsers());
        } catch (JAXBException e) {
            e.printStackTrace();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    public static UserRepository getInstance() {
        if (repository == null) {
            repository = new UserRepository();
        }

        return repository;
    }

    public HashSet<User> getUsers() {
        return this.users;
    }

    public boolean contains(User user) {
        return this.users.contains(user);
    }

    public void addUser(User user) {
        this.users.add(user);
        updateXMLFile();
    }

    public void removeUser(User user) {
        this.users.remove(user);
    }

    public User getUserById(int id) {
        for (User currentUser : this.users) {
            if (currentUser.getId() == id) {
                return currentUser;
            }
        }

        return null;
    }

    public User getUserByEmail(String email) {
        for (User currentUser : this.users) {
            if (currentUser.getEmail().equals(email)) {
                return currentUser;
            }
        }

        return null;
    }

    public int getSize() {
        return this.users.size();
    }

    public void editUser(int id, User o) {
        User editUser = this.getUserById(id);
        removeUser(this.getUserById(id));
        editUser = o;

        this.addUser(editUser);
    }

    public void updateXMLFile() {
        XMLWorker worker = new XMLWorker();
        try {
            worker.writeToXMLFile(this.xmlFilePath, this.users);
        } catch (JAXBException e) {
            e.printStackTrace();
        }
    }

    @Override
    public String toString() {
        return "UserRepository [users=" + this.users + "]";
    }
}

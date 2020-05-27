package models;

import java.util.HashSet;

public class UserRepository {
    private static UserRepository repository;

    private HashSet<User> users = new HashSet<User>();

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

    @Override
    public String toString() {
        return "UserRepository [users=" + this.users + "]";
    }
}

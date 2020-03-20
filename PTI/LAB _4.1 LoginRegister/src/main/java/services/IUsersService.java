package services;

public interface IUsersService {
    void create(String name, String username, String password, String confirmPassword);
}

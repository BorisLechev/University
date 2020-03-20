package services.base;

import services.IUsersService;

import javax.inject.Inject;
import javax.persistence.EntityManager;

public class UsersService implements IUsersService {
    private final EntityManager entityManager;

    @Inject
    public UsersService(EntityManager entityManager) {
        this.entityManager = entityManager;
    }

    @Override
    public void create(String name, String username, String password, String confirmPassword) {

    }
}

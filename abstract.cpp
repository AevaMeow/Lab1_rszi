#include <iostream>
using namespace std;

// 4
class AbstractEntity {
    public:
        virtual ~AbstractEntity() {}
    };
    
class AccountEntity : public AbstractEntity {
    public:
        AccountEntity() { cout << "AccountEntity создан" << endl; }
    };
    
class RoleEntity : public AbstractEntity {
    public:
        RoleEntity() { cout << "RoleEntity создан" << endl; }
    };
    
class IRepository {
    public:
        virtual void Save(AbstractEntity& entity) = 0;
        virtual ~IRepository() {}
    };
    
class AccountRepository : public IRepository {
    public:
        void Save(AbstractEntity& entity) override {
            cout << "AccountRepository: сохранение AccountEntity" << endl;
        }
    };
    
class RoleRepository : public IRepository {
    public:
        void Save(AbstractEntity& entity) override {
            cout << "RoleRepository: сохранение RoleEntity" << endl;
        }
    };
    
int main() {
// 4
    AccountEntity account;
    RoleEntity role;

    AccountRepository accountRepo;
    RoleRepository roleRepo;

    accountRepo.Save(account);
    roleRepo.Save(role);
    return 0;

}
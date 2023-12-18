#include <iostream>
#include <string>
#include <vector>
using namespace std;


class User
        {
        private:
            string username,password;
        public:
            User(string& name,string& pass):username(name),password(pass){}
            string getUsername()
            {
                return username;
            }
            string getPassword()
            {
                return password;
            }
        };

class UserManager
        {
        private:
            vector<User> users;
        public:
            void registerUser()
            {
                string username,password;
                cout << "\t\tEnter user name:";
                cin >> username;
                cout << "\t\tEnter password: ";
                cin >> password;

                User newUser(username,password);
                users.push_back(newUser);

                cout << "\t\tUser registered..\n";

            }
            bool loginUser(string& name,string& pass)
            {
                for(auto & user : users)
                {
                    if (user.getUsername()==name && user.getPassword()==pass)
                    {
                        cout << "\t\t Login Successfully\n";
                        return true;
                    }

                }
                cout << "\t\tWrong username, password\n";
                return false;
            }
            void showUser()
            {
                cout<< "\t\t---User List---\n";
                for(auto & user : users)
                {
                    cout << "\t\tUsername: " << user.getUsername() <<endl;
                }
            }

            void searchUser(string& username)
            {
                int checker = 0;
                for(auto & user : users)
                {
                    if(user.getUsername()==username)
                    {
                        cout << "\t\tUser has found.\n";
                        checker = 1;
                    }

                }
                if(checker == 0)
                    cout << "\t\tUser hasn't found.\n";
            }

            void deleteUser(string& username)
            {
                vector<User>::iterator it;
                it = users.begin();
                while(it != users.end())
                {

                    if(it->getUsername() ==username)
                        break;
                    it++;
                }
                if(it !=users.end())
                {
                    users.erase(it);
                    cout << "\t\tDeleting successfully.\n";
                }
                else
                    cout << "\t\tError with delete.\n";

            }
        };
int main() {

    UserManager  userManage;
    int op;
    char choice;
    do{
        system("cls");
        cout << "\n\n\t\t1.Register User\n";
        cout << "\t\t2. Login\n";
        cout << "\t\t3.Show User List\n";
        cout << "\t\t4.Search user\n";
        cout << "\t\t5.Delete User\n";
        cout << "\t\t6.Exit\n";
        cout << "\t\tEnter your choice :";
        cin >> op;
        string username, password;
        switch (op) {
            case 1:
                userManage.registerUser();
                break;

            case 2:
                cout << "\t\tEnter User: ";
                cin >> username;
                cout << "\t\tEnter Password: ";
                cin >> password;
                userManage.loginUser(username, password);
                break;
            case 3:
                userManage.showUser();
                break;
            case 4:
                cout << "\t\tEnter username:";
                cin >> username;
                userManage.searchUser(username);
                break;
            case 5:
                cout << "\t\tEnter username to delete:";
                cin >> username;
                userManage.deleteUser(username);
                break;
            case 6:
                exit(1);
            default:
                cout << "error\n";
                break;
        }
        cout << "\t\tDo you want to continue: [y/Y]";
        cin >> choice;
    }while(choice =='y'||choice=='Y');

    return 0;

}
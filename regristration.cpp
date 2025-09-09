#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class User {
public:
    string firstName, lastName, password, email, number, location;

    // Signup
    void signup() {
        cout << "First Name: ";
        getline(cin, firstName);
        cout << "Last Name: ";
        getline(cin, lastName);
        cout << "Password: ";
        getline(cin, password);
        cout << "Email: ";
        getline(cin, email);
        cout << "Mobile Number: ";
        getline(cin, number);
        cout << "Location: ";
        getline(cin, location);
    }

    // Convert user data into CSV format
    string toString() const {
        stringstream ss;
        ss << firstName << "," << lastName << "," << password << ","
           << email << "," << number << "," << location << "\n";
        return ss.str();
    }

    // Save all users from vector to file
    static void saveUsers(const vector<User>& users) {
        ofstream fout("users.txt", ios::app);
        for (auto& u : users) fout << u.toString();
        fout.close();
        cout << "\n Users saved successfully!\n";
    }

    // Login
    static void login(const string& email, const string& password) {
        ifstream fin("users.txt");
        string line;
        while (getline(fin, line)) {
            stringstream ss(line);
            string fname, lname, pass, mail, num, loc;
            getline(ss, fname, ',');
            getline(ss, lname, ',');
            getline(ss, pass, ',');
            getline(ss, mail, ',');
            getline(ss, num, ',');
            getline(ss, loc, ',');

            if (mail == email && pass == password) {
                cout << "\n Login Successful! Welcome "
                     << fname << " " << lname << " from " << loc << endl;
                return;
            }
        }
        cout << "\n Login Failed!\n";
    }
};

int main() {
    int choice;
    cout << "1. Signup\n2. Login\nEnter choice: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        int n;
        cout << "How many users? ";
        cin >> n;
        cin.ignore();

        vector<User> users;
        for (int i = 0; i < n; i++) {
            cout << "\n--- Signup User " << i + 1 << " ---\n";
            User u;
            u.signup();
            users.push_back(u);
        }
        User::saveUsers(users);
    }
    else if (choice == 2) {
        string email, password;
        cout << "Email: ";
        getline(cin, email);
        cout << "Password: ";
        getline(cin, password);
        User::login(email, password);
    }
    else {
        cout << " Invalid choice!\n";
    }
    return 0;
}

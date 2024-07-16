#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Base class for both User and Admin
class Person {

protected:
    string name;

public:
    string getName() const
    {
        return name;
    }
};

/// =============== USER ===================

class User : public Person {
    // Private member variables
    string name, dept, password;
    char section;
    int id, batch;

public:
    // Constructor to initialize user details
    User(string n, string d, string p, char s, int i, int b)
    {
        this->name = n;
        this->dept = d;
        this->password = p;
        this->section = s;
        this->id = i;
        this->batch = b;
    }

    // Method to update user details
    void updateUserDetails(string newDept, char newSection, string newPassword)
    {
        this->dept = newDept;
        this->section = newSection;
        this->password = newPassword;
    }

    // Getter methods to access user information
    string getName()
    {
        return name;
    }
    string getDept()
    {
        return dept;
    }
    string getPass()
    {
        return password;
    }
    char getSection()
    {
        return section;
    }
    int getId()
    {
        return id;
    }
    int getBatch()
    {
        return batch;
    }
};

/// =========== USER =============


/// ============= ADMIN ===============

class Admin : public Person {

public:
    string name = "Shifa";
    int code = 123456;

    // Getter methods for admin information
    string getName()
    {
        return name;
    }
    int getCode()
    {
        return code;
    }
};

/// ============= ADMIN ===============


/// ================= ADMIN MANAGER ===================

class AdminManager {

private:
    Admin admin;

public:
    int loggedIndex;
    AdminManager() : loggedIndex(-1) {} // loggedIndex = - 1

    // Method for admin login
    bool adminLogin(string n, int key)
    {
        if (admin.getName() == n && admin.getCode() == key)
        {
            if (loggedIndex != -1)
            {
                cout << "\t\t\tAnother Admin is already logged in. Please log out first" << endl;
                return false;
            }

            loggedIndex = 1;
            cout << "\t\tAdmin Login Successful" << endl;
            return true;
        }

        cout << "\t\t invalid name/code" << endl;
        return false;
    }

    // Method for admin logout
    void logoutAdmin()
    {
        if (loggedIndex != -1)
        {
            cout << "\t\t\t Logout Successful" << endl;
            loggedIndex = -1;
        }
        else
        {
            cout << "Please log in as admin" << endl;
        }
    }
};

/// =================== ADMIN MANAGER ===================


/// ============ USER MANAGER ==================

class UserManager {

public:
    vector<User> users;
    int loggedIndex; // index of the currently logged in user
    UserManager() : loggedIndex(-1) {} // loggedIndex = - 1 // loggedIndex = false;

    // Method for user registration
    void RegisterUser()
    {
        string name, dept, password;
        char section;
        int id, batch;

        cout << "\t\t\t Registration // Login Requirements" << endl;

        cout << "1. Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "2. ID: ";
        cin >> id;

        cout << "3. Dept: ";
        cin.ignore();
        getline(cin, dept);

        cout << "4. Section: ";
        cin >> section;

        cout << "5. Batch: ";
        cin >> batch;

        cin.ignore();
        cout << "6. Create password: ";
        getline(cin, password);

        // Creating a new user object and adding it to the vector
        User newUser(name, dept, password, section, id, batch);
        users.push_back(newUser);

        cout << "\t\tUser registered" << endl;
        system("pause");
        system("cls");
    }

    // Method for user login
    bool loginUser(string name, int id, string pass)
    {
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i].getName() == name && users[i].getId() == id && users[i].getPass() == pass)
            {
                if (loggedIndex != -1)
                {
                    cout << "\t\t\tAnother user logged in. Please logout first" << endl;
                    return false;
                }

                loggedIndex = 1;
                cout << "\t\t\t Login Successful" << endl;
                return true;
            }
        }

        cout << "\t\t\t Invalid Username/Password/ID" << endl;
        return false;
    }

    // Method for user logout
    void LogoutUser()
    {
        if (loggedIndex != -1)
        {
            cout << "\t\t\t Logout Successful" << endl;
            loggedIndex = -1;
        }
        else
        {
            cout << "\t\t\tNo user is currently logged in. Please login" << endl;
        }
    }

    // Method to display user profile
    void displayProfile(string name)
    {
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i].getName() == name)
            {
                cout << "\t\t\t =-=-=-=-= Profile =-=-=-=-=\n" << endl;
                cout << "\t\tName: " << users[i].getName() << endl;
                cout << "\t\tID: " << users[i].getId() << endl;
                cout << "\t\tDept: " << users[i].getDept() << endl;
                cout << "\t\tSection: " << users[i].getSection() << endl;
                cout << "\t\tBatch: " << users[i].getBatch() << endl;
                return;
            }
        }

        cout << "\t\tUser not found" << endl;
    }

    // Method to edit user profile
    void EditProfile(string name)
    {
        bool found = false;
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i].getName() == name)
            {
                found = true;

                string dept, pass;
                char section;

                cout << "\t\t\t Editing Profile" << endl;
                cout << "New Department: ";
                cin.ignore();
                getline(cin, dept);

                cout << "New Section: ";
                cin >> section;

                cin.ignore();
                cout << "New Password: ";
                getline(cin, pass);

                users[i].updateUserDetails(dept, section, pass);
                cout << "\t\t\t Profile updated successfully" << endl;
            }
        }
        if (!found)
        {
            cout << "\t\t\t User not found" << endl;
        }
    }
};

/// ========== USER MANAGER ============


/// ============ TASK ===============

class Task {

private:
    string name;
    string description;

public:
    Task(string n, string desc) : name(n), description(desc) {} // name = n; desc = description

    string getName()
    {
        return name;
    }

    string getDescription()
    {
        return description;
    }
};

/// ============ TASK =============


/// ========== TASK MANAGER ===========

class TaskManager {

private:
    vector<Task> tasks;

public:
    void addTask()
    {
        string name, desc;
        cout << "\n\t\t\t:: Project Add Section :: " << endl;
        cout << "\t\t\tEnter project name: " << endl;
        cin.ignore();
        getline(cin, name);
        cout << "\t\t\tEnter project description in short: " << endl;
        getline(cin, desc);

        Task newTask(name, desc);
        tasks.push_back(newTask);

        cout << "\t\t\tProject added successfully" << endl;
        system("pause");
        system("cls");
    }

    void displayTasks()
    {
        cout << "Tasks:" << endl;
        for (auto &task : tasks)
        {
            cout << "Name: " << task.getName() << ", Description: " << task.getDescription() << endl;
        }
    }
};

/// ============ TASK MANAGER ===========


/// =========== MAIN FUNCTION ==============

int main()
{
    UserManager usermanage;
    AdminManager adminmanage;
    TaskManager taskmanage;
    int c;
    char d;

    do {
        cout << "\n\t\t Bangladesh Army University of Science & Technology" << endl;
        cout << "\t\t\t PROJECT SUPERVISION SYSTEM (PSS)" << endl;
        cout << "\t\t\t\t 1. Register User" << endl;
        cout << "\t\t\t\t 2. Login User" << endl;
        cout << "\t\t\t\t 3. Logout User" << endl;
        cout << "\t\t\t\t 4. Login Admin" << endl;
        cout << "\t\t\t\t 5. Logout Admin" << endl;
        cout << "\t\t\t\t 6. My Profile" << endl;
        cout << "\t\t\t\t 7. Exit" << endl;
        cout << "Enter your Choice: ";

        cin >> c;

        switch (c)
        {
        case 1:
        {
            usermanage.RegisterUser();
            break;
        }
        case 2:
        {
            string name, password;
            int id;
            cout << "Name: ";
            cin >> name;
            cout << "ID: ";
            cin >> id;
            cout << "Password: ";
            cin >> password;
            usermanage.loginUser(name, id, password);
            system("pause");
            system("cls");
            break;
        }
        case 3:
        {
            usermanage.LogoutUser();
            break;
        }
        case 4:
        {
            string n;
            int key;
            cout << "Name: " << endl;
            cin >> n;
            cout << "Admin Code: " << endl;
            cin >> key;
            adminmanage.adminLogin(n, key);

            bool backToMainMenu = false;
            int abc;
            do
            {
                cout << "\n\t\t\t Admin Options" << endl;
                cout << "\t\t\t 1. Registered Students" << endl;
                cout << "\t\t\t 2. Project List" << endl;
                cout << "\t\t\t 3. Go back" << endl; // Added option to go back
                cout << "Enter your choice: ";
                cin >> abc;

                switch (abc)
                {
                case 1:
                {
                    if (adminmanage.loggedIndex == -1)
                    {
                        cout << "Please log in as admin first." << endl;
                        break;
                    }

                    if (!usermanage.users.empty())
                    {
                        cout << "\t\t\t========= Registered Students =============" << endl;
                        for (int i = 0; i < usermanage.users.size(); i++)
                        {
                            cout << "\n\n-----------------------------" << endl;
                            cout << "Name: " << usermanage.users[i].getName() << endl;
                            cout << "ID: " << usermanage.users[i].getId() << endl;
                            cout << "Department: " << usermanage.users[i].getDept() << endl;
                            cout << "Section: " << usermanage.users[i].getSection() << endl;
                            cout << "Batch: " << usermanage.users[i].getBatch() << endl;
                            cout << "-----------------------------" << endl;
                            cout << endl;
                        }
                    }
                    else
                    {
                        cout << "No registered students." << endl;
                    }
                    break;
                }
                case 2:
                    taskmanage.displayTasks();
                    break;
                case 3:                    // If the admin chooses to go back
                    backToMainMenu = true; // Set flag to true to exit the loop
                    break;
                default:
                    cout << "Invalid choice" << endl;
                    break;
                }
            }
            while (!backToMainMenu);
            break;
        }
        case 5:
        {
            adminmanage.logoutAdmin();
            break;
        }
        case 6:
        {
            if (usermanage.loggedIndex == -1)
            {
                cout << "Please login first." << endl;
                break;
            }

            string name;
            cout << "Enter your name: ";
            cin >> name;
            usermanage.displayProfile(name);

            bool backToMainMenu = false;
            int cdc;

            cout << endl;
            cout << "\t\t\t === OTHER OPTIONS ===" << endl;
            cout << "\t\t\t 1. Edit Profile" << endl;
            cout << "\t\t\t 2. Add Task" << endl;
            cout << "\t\t\t 3. Go Back" << endl;
            cout << "Enter your choice: ";
            cin >> cdc;

            switch (cdc)
            {
            case 1:
            {
                char choice;
                cout << "Do you want to edit your profile? (y/n): ";
                cin >> choice;
                if (choice == 'y' || choice == 'Y')
                {
                    usermanage.EditProfile(name);
                }
                break;
            }

            case 2:
            {
                taskmanage.addTask();
                break;
            }
            default:
                break;
            }

            break;
        }
        case 7: {
            cout << "Thanks for using the system" << endl;
            d = 'n' || 'N';
            break;
        }
        }

        cout << "Continue? [y/n]" << endl;
        cin >> d;
    }
    while (d == 'y' || d == 'Y');
}

/// =========== MAIN FUNCTION =================
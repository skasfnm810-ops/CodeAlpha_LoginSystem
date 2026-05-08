#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Registration Function
void registerUser() {

    string username, password;

    cout << "\n============================\n";
    cout << "      USER REGISTRATION\n";
    cout << "============================\n";

    cout << "Create a Username: ";
    cin >> username;

    cout << "Create a Password: ";
    cin >> password;

    // Check if username already exists
    ifstream checkFile(username + ".txt");

    if (checkFile.is_open()) {
        cout << "\nThis username already exists!";
        cout << "\nPlease try another username.\n";
        checkFile.close();
        return;
    }

    checkFile.close();

    // Save data in file
    ofstream file(username + ".txt");

    file << username << endl;
    file << password << endl;

    file.close();

    cout << "\nRegistration Successful!";
    cout << "\nNow you can login.\n";
}

// Login Function
void loginUser() {

    string username, password;
    string storedUsername, storedPassword;

    cout << "\n============================\n";
    cout << "          USER LOGIN\n";
    cout << "============================\n";

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    ifstream file(username + ".txt");

    if (!file.is_open()) {
        cout << "\nUser not found!";
        cout << "\nPlease register first.\n";
        return;
    }

    getline(file, storedUsername);
    getline(file, storedPassword);

    file.close();

    if (username == storedUsername && password == storedPassword) {

        cout << "\nLogin Successful!";
        cout << "\nWelcome, " << username << "!\n";

    } else {

        cout << "\nIncorrect Password!";
        cout << "\nTry again.\n";
    }
}

// Main Function
int main() {

    int choice;

    while (true) {

        cout << "\n===================================";
        cout << "\n   LOGIN & REGISTRATION SYSTEM";
        cout << "\n===================================";
        cout << "\n1. Register New Account";
        cout << "\n2. Login Existing Account";
        cout << "\n3. Exit";
        cout << "\n-----------------------------------";
        cout << "\nEnter Your Choice (1-3): ";

        cin >> choice;

        switch (choice) {

            case 1:
                registerUser();
                break;

            case 2:
                loginUser();
                break;

            case 3:
                cout << "\nProgram Closed Successfully.\n";
                return 0;

            default:
                cout << "\nInvalid Choice!";
                cout << "\nPlease enter 1, 2 or 3.\n";
        }
    }

    return 0;
}
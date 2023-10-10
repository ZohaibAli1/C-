#include <fstream>
#include <iostream>
#include <vector>
#include<string>
#include<stdlib.h>
#include<windows.h>
using namespace std;

class CarAdmin {
public:
    void add_car() {
        ofstream file("car_details.txt", ios::app);
        if (file.is_open()) {
            bool done = false;
            while (!done) {
                file << "Add Car Details" << endl << endl;
                cout << "Company Made Car: ";
                cin >> manufactured;
                file << "Company Made Car: " << manufactured << endl;
                cout << "Color: ";
                cin >> color;
                file << "Color: " << color << endl;
                cout << "Engine HP: ";
                cin >> engine;
                file << "Engine HP: " << engine << endl;
                cout << "Miles Per KM: ";
                cin >> miles;
                file << "Miles Per KM: " << miles << endl;
                cout << "Add another car? (y/n) ";
                char response;
                cin >> response;
                if (response == 'n') {
                    done = true;
                    file.close();
                }
            }
        }
        else {
            cout << "Error: could not open file." << endl;
        }
    }   
    void delete_car() {
        vector<string> cars;
        ifstream file("car_details.txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                cars.push_back(line);
            }
            file.close();
        }
        else {
            cout << "Error: could not open file." << endl;
        }

        cout << "List of Cars:" << endl;
        for (int i = 0; i < cars.size(); i++) {
            cout << i + 1 << ". " << cars[i] << endl;
        }
        cout << "Enter the number of the car to delete: " << endl;
    }
private:
    string manufactured, color;
    int engine, miles;
};
class User {
public:
    void view(int option) {
        switch (option) {
        case 1:
            cout << "Enter Your Details Below" <<  endl;
            write_details();
            break;
        case 2:
            read_details();
            break;
        }
    }
private:
     string name;

    void write_details() {
         ofstream file("user_details.txt",  ios::app);
        if (file.is_open()) {
             cout << "Enter Your Name." <<  endl;
             cin >> name;
            file << name <<  endl;
            file.close();
             cout << "Details saved successfully." <<  endl;
        }
        else {
             cout << "Could not write to file." <<  endl;
        }
    }

    void read_details() {
         ifstream file("user_details.txt");
        if (file.is_open()) {
             string line;
            bool name_exists = false;
            while (getline(file, line)) {
                if (line == name) {
                    name_exists = true;
                    break;
                }
            }
            file.close();
            if (name_exists) {
                 cout << "Name exists in file." <<  endl;
            }
            else {
                 cout << "Name does not exist in file." <<  endl;
                write_details();
            }
        }
        else {
             cout << "Could not open file." <<  endl;
        }
    }
};

class MyApp {
public:
    void run() {
    	AD:
        cout << "Welcome to my app!" << endl;
        
        CarAdmin admin;
        
        cout << "1. Admin View" << endl;
        cout << "2. User View" << endl;
        
        int option;
        cin >> option;
        
        switch (option) {
            case 1:
            {
            cout<<"Wirte Name and Admin Password."<<endl;
            string username, password;
        	cout << "Enter Name: ";
        	cin >> username;
        	cout << "Enter password: ";
        	cin >> password;
        	if (username == "admin" && password == "admin") {
            cout << "Welcome, admin!" << endl;
        }
        else {
            cout << "Invalid credentials." << endl;
            Sleep(1000);
            cout <<"TryAGAIN"<<endl;
            Sleep(1000);
            system("cls");
            goto AD;
            
        }
    }
        
                cout << "1. Add Car" << endl;
                cout << "2. Delete Car" << endl;
                
                cin >> option;
                
                if (option == 1) {
                    admin.add_car();
                } else if (option == 2) {
                    admin.delete_car();
                }
                break;
            case 2:
                
                break;
            default:
            cout << "Invalid option." << endl;
            Sleep(1000);
            system("cls");
            goto AD;
                break;
        }
    }
};

int main() {
    MyApp app;
    app.run();
    User user;
    int option;
    cout << "1. Enter Your Details." << std::endl;
    cout << "2. View Your Details." << std::endl;
    cout << "Enter an option: ";
    cin >> option;
    user.view(option);
    return 0;
}



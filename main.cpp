#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h> 

using namespace std;

void admin_view() {
    cout << "Welcome, admin!" << endl;
    cout << "1. Add Car" << endl;
    cout << "2. Delete Car" << endl;
}

void user_view() {
    cout << "Welcome, user!" << endl;
    cout << "1. Register " << endl;
    cout << "2. Login Existing" << endl;
}

int main() {
    string manufactured, color, engine,name;
    int miles;
    string username, password;
user_type:
    int user_type;
    cout << "Are you an admin or a regular user?" << endl;
    cout << "1. Admin" << endl;
    cout << "2. User" << endl;
    cout << "Enter option: ";
    cin >> user_type;

    if (user_type == 1) {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        if (username == "admin" && password == "admin") {
            admin_view();
        }
        else {
            cout << "Invalid credentials. Aborting." << endl;
            goto user_type;
        }
    }
    else if (user_type == 2) {
        user_view();
    }
    else {
        cout << "Invalid option. Aborting." << endl;
        goto user_type;
    }

    int option;
    cout << "Enter option: ";
    cin >> option;

    if (user_type == 1) {
        switch (option) {
        case 1:
        {
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
                        goto user_type;
                    }
                }
            }
            else {
                cout << "Error: could not open file." << endl;
            }
        }
        break;
        case 2:
        {
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
        }
    }
    if (user_view) {
        switch (option) {
        case 1:{
        	cout<<"Entre Details Below"<<endl;
            ofstream file("user_details.txt", ios::app);
            if (file.is_open()){
            	bool done = false;
            	while(!done){
	            cout<<"Entre Your Name."<<endl;
            	cin>>name;
            	file.close();
            goto user_type;   
            } 
        }
			else {
				cout<<"Could Not Write"<<endl;
			} 
			break;
		}
        case 2:
		{
		cout << "Enter Your Name." << endl;
	    cin >> name;
	    ifstream read_file("user_details.txt");
	    bool name_exists = false;
	    string line;
	    while (getline(read_file, line)) {
	        if (line == name) {
	        name_exists = true;
	        ifstream file("car_details.txt");
	    	if (file.is_open()) {
	        string line;
	        while (getline(file, line)) {
	            cout << line << endl;
	        }
	        file.close();
	    }
    else {
        cout << "Error: could not open file." << endl;
    }
	    break;
	            break;
	        }
	    }
	    read_file.close();
	    if (!name_exists) {
	        cout << "Sorry, your name was not found in the file." << endl;
	        break;
	    }
	    
		    }         
				break;
		}        
	}
	    return 0;
}
    








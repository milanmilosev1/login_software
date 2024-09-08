#include <iostream>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;


int logging_in(){
    string username;
    string line;
    string password;
    string line2;
    fstream file("login_credentials.txt", ios::in);
    if(file){
        cout << "Enter your username: " << endl;
        cin >> username;
        cout << endl;
        cout << "Enter your password" << endl;
        cin >> password;
        cout << endl;

        bool userFound = false;
        while (getline(file, line) && getline(file, line2)){
            if(line == username){
                userFound = true;   
                if(line2 == password){
                    cout << "Login sucessful!" << endl;
                    file.close();
                    return 0;
                }
                else{
                    cout << "Wrong password! Exit code -1" << endl;
                    file.close(); 
                    return -1;
                }
            }
        }
        if(!userFound){
            cout << "Username not found! Exit code -2" << endl;
        }
        file.close();
        return -2;
    }
    else{
        cout << "Error while opening file! Code -5" << endl;
        return -5;
    }
}


int registering(){
    string username;
    string password;
    string line;

    fstream file("login_credentials.txt", ios::in);
    if(file){
        cout << "Enter your desired username" << endl;
        cin >> username;

        bool usernameTaken = false;

        while(getline(file, line)){
            if(username == line){
                usernameTaken = true;
                break;
            }
            getline(file, line);
        }
        file.close();

        if(usernameTaken){
            cout << "Username is already taken! " << endl;
            return -3;
        }

        fstream fileOut("login_credentials.txt", ios::app);
        
        if(!fileOut){
            cout << "Error while opening file! Exit code -4" << endl;
            return -4;
        }

        cout << "Enter your desired password" << endl;
        cin >> password;

        fileOut << username << endl;
        fileOut << password << endl;
        fileOut << endl;

        file.close();
        cout << endl << "User created sucessfully!" << endl;
        return 4;
    }
}


int main(){
    string login_or_register;

    cout << "Login or Register?(use lowercase letters)" << endl;
    cin >> login_or_register;


    if(login_or_register == "login"){
        logging_in();
    }

    else if(login_or_register == "register"){
        registering();
    }


    return 0;
}
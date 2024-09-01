#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
class myclass
{
private:
    int sum, uset, n = 0;
    string name;
    string hash;
    string psswd;
    string str[10];
    // string arr[8] = {};

public:
    void tryagain()
    {
        int choose;
        cout << "Do you want to exit ?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cout << "Enter your choice : ";
        cin >> choose;
        switch (choose)
        {
        case 1:
            system("clear");
            cout << "----------------------------------------------------------" << endl;
            cout << "\t\tThanks for using Z+ Security System" << endl;
            cout << "----------------------------------------------------------" << endl;

            break;
        case 2:
            system("clear");
            menu();
            break;

        default:
            cout << "Please enter a valid option." << endl;
            break;
        }
    }
    void loginpage()
    {
        // system("clear");
        cout << "----------------------------------------------------------" << endl;
        cout << "Login Successfull" << endl;
        cout << "----------------------------------------------------------" << endl;
        tryagain();
    }
    int converter(string set)
    {
        sum = 0;
        for (int i = 0; i < set.length(); i++)
        {

            //  cout << "Set : " << set[i] << endl;
            //  cout << "" << static_cast<int>(set[i]) << endl;
            sum = sum + static_cast<int>(set[i]);
        }

        uset = (sum % 256);
        // cout << " Hash Number code for perimeter " << endl;
        cout << "===>" << uset << endl;
        return uset;
    }
    void check()
    {
        // std::ofstream outfile("Zplus.txt");
        std::ifstream infile("Zplus.txt", ios::in);
        string line;
        int found = 0;
        if (infile.is_open())
        {
            // cout << "User entered Password : " << hash << endl;
            while (getline(infile, line))
            {

                if (line.find("Name : " + name) != string::npos)
                {
                    // cout << "Name : " << name << " is found in file" << endl;
                    found = 1;
                    // cout << "This is break statement" << endl;
                    // break;
                }
                else if (line.find("Hash-Code : " + hash) != string::npos)
                {

                    if (hash.length() == 14)
                    {
                        //  cout << "File Hash-Code : " << hash << " is found in file" << endl;
                        found++;
                    }
                    else
                    {
                        cout << "Error : Password is incorrect!" << endl;
                        break;
                    }
                }
                else if (found == 2)
                {
                    cout << "Username & Hash code is found in file" << endl;
                    break;
                }
            }

            // while (getline(infile, line))
            // {
            //     if (line.find(name) && line.find(uset))
            //     {
            //         found = true;
            //         // if (line.find(to_string(uset)))
            //         // {

            //         // }
            //     }
            // }
        }
        else
            cout << "Error : File is not open !" << endl;
        infile.close();
        if (found == 2)
        {
            loginpage();
        }
        else
        {
            system("clear");
            cout << "Erro : This account is not exist in Server" << endl;
            tryagain();
        }
    }
    void newuser()
    {
        cout << "Enter your name : ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter your password : ";
        cin.ignore(0, '\n');
        getline(cin, psswd);
        // address(name, psswd);
        //   psswd = psswd + "enc";
        //   converter(name);
        //  ===>converter(psswd);
        //  if (psswd.length() > 5)
        //  {
        //      cout << "Please enter a password whose length is greater than 5" << endl;
        //  }
        cout << "----------------------------------------------------------" << endl;

        cout << "Name : " << name << "\nPassword : " << psswd << "\nNew Password : " << &psswd << endl;
        cout << "----------------------------------------------------------" << endl;

        cout << "===>Please save new password it is your hash-code and use it for login"
             << endl;
        std::ofstream outfile("Zplus.txt", ios::app);
        if (outfile.is_open())
        {
            outfile << "\nName : " << name << "\nPassword : " << psswd << "\nHash-Code : " << &psswd << endl;
        }
        else
            cout << "Error : File is not open !" << endl;
        outfile.close();
        menu();
    }

    void login()
    {
        cout << "----------------------------------------------------------" << endl;

        cout << "Please enter Hash-Code as a password"

             << endl;
        cout << "----------------------------------------------------------" << endl;

        cout << "Enter your name : ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter your password : ";
        cin.ignore(0, '\n');
        getline(cin, hash);
        // psswd = psswd + "enc";
        //  converter(name);
        // converter(psswd);
        check();
    }
    void menu()
    {
        int choice;
        cout << "----------------------------------------------------------" << endl;
        cout << "\t\tZ+ Security System" << endl;
        cout << "\t\tBased on CRYPTOGRAPHY" << endl;
        cout << "\t\tInspired by SHA-256 " << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << "1. Login" << endl;
        cout << "2. New-User" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            login();
            break;
        case 2:
            newuser();
            break;
        case 3:
            system("clear");
            cout << "----------------------------------------------------------" << endl;
            cout << "\tThanks for using Z+ Security System" << endl;
            cout << "----------------------------------------------------------" << endl;
            break;

        default:
            cout << "Please enter a valid option." << endl;
            break;
        }
    }
};
int main()
{
    myclass obj;
    obj.menu();
    return 0;
}
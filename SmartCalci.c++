#include <iostream>
#include <fstream>
#include <string.h>
#include <unistd.h>
using namespace std;
class myclass
{
private:
    int a, b, c;
    string name;
    int newAmount = 0, oldAmount = 0, payAmount = 0;

public:
    void tryanother()
    {
        // system("clear");
        cout << "Do you want to exit ?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            system("clear");
            cout << "----------------------------------------------------------" << endl;
            cout << "\tThanks for using our Smart Calculator" << endl;
            cout << "----------------------------------------------------------" << endl;
            break;
        case 2:
            menu();
            break;
        default:
            cout << "Please enter a valid option." << endl;

            break;
        }
    }
    void add(int x, int y)
    {
        c = x + y;
        cout << "----------------------------------------------------------" << endl;
        cout << "" << a << " + " << b << " =  " << c << endl;
        cout << "----------------------------------------------------------" << endl;

        tryanother();
    }
    void sub(int x, int y)
    {
        c = x - y;
        if (c < 0)
        {
            cout << "----------------------------------------------------------" << endl;
            cout << " " << a << " - " << b << " =  " << c << endl;
            cout << "----------------------------------------------------------" << endl;

            tryanother();
        }
    }
    void multiply(int x, int y)
    {
        c = x * y;
        cout << "----------------------------------------------------------" << endl;
        cout << "" << a << " * " << b << " =  " << c << endl;
        cout << "----------------------------------------------------------" << endl;

        tryanother();
    }
    void divide(int x, int y)
    {
        c = a / b;
        cout << "----------------------------------------------------------" << endl;
        cout << "" << a << " /  " << b << " =  " << c << endl;
        cout << "----------------------------------------------------------" << endl;

        tryanother();
    }
    void debt()
    {
        cout << "----------------------------------------------------------" << endl;
        cout << "Enter your name : ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter amount of debt : ";
        cin >> payAmount;

        cout << "----------------------------------------------------------" << endl;

        cout << "Name : " << name << "\nAmount : " << payAmount << "\nSuccessfully registered on Debt file" << endl;
        cout << "----------------------------------------------------------" << endl;
        std::ofstream outfile("debt.txt", ios::app);
        if (outfile.is_open())
        {
            outfile << "----------------------------------------------------------" << endl;
            outfile << "Name : " << name << "\nAmount : " << payAmount << endl;
            outfile << "----------------------------------------------------------" << endl;
        }
        else
            cout << "Error : File is not open !" << endl;
        outfile.close();
        tryanother();
    }
    void display()
    {
        std::ifstream infile("debt.txt");
        string line;
        if (infile.is_open())
        {
            while (getline(infile, line))
            {
                cout << line << endl;
            }
        }
        else
            cout << "Error : File is not open !" << endl;

        infile.close();
    }
    void paydebt()
    {
        display();
        cout << "Enter your name : ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter amount you want to pay : ";
        cin >> payAmount;
        std::ifstream infile("debt.txt", ios::app);
        std::ofstream outfile("temp.txt", ios::app);
        string line;
        int found = 0;
        bool exit = false;
        if (infile.is_open())
        {
            while (!exit)
            {
                getline(infile, line);
                if (line.find("Name : " + name) != string::npos)
                {
                    found = 1;
                }
                else if (found == 1 && line.find("Amount : ") != string::npos)
                {
                    string amountStr = line.substr(9);
                    oldAmount = stoi(amountStr);
                    newAmount = oldAmount - payAmount;
                    outfile << "----------------------------------------------------------" << endl;
                    outfile << "Name : " << name << "\nAmount : " << newAmount << endl;
                    outfile << "----------------------------------------------------------" << endl;
                    found++;
                    exit = true;
                }
                else
                {
                    outfile << line << endl;
                }
            }
        }
        else
            cout << "Error : ifstream file is not open !" << endl;
        infile.close();
        outfile.close();
        remove("debt.txt");
        rename("temp.txt", "debt.txt");
        // std::ofstream newOut("newtemp.txt", ios::app);
        // if (newOut.is_open())
        // {
        //     //  newAmount = (oldAmount - payAmount);

        //     newOut << "----------------------------------------------------------" << endl;
        //     newOut << "Name : " << name << "\nAmount : " << newAmount << endl;
        //     newOut << "----------------------------------------------------------" << endl;
        // }

        // else
        //     cout << "Error : ifstream file is not open !" << endl;
        // newOut.close();
        // remove("debt.txt");
        // rename("newtemp.txt", "debt.txt");
        //   cout << "NewAmount : " << newAmount << endl;
        cout << "Record is updated successfully" << endl;
        tryanother();
    }
    void menu()
    {
        system("clear");
        int choice;
        cout << "----------------------------------------------------------" << endl;
        cout << "\t\t\tSmart Calculator" << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << "Please select any one option " << endl;
        cout << "1. Debt" << endl;
        cout << "2. Pay-Debt" << endl;
        cout << "3. Only Calculation" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            debt();
            break;
        case 2:
            paydebt();
            break;
        case 3:
            calculation();
            break;
        default:
            cout << "Please enter a valid option." << endl;
            break;
        }
    }

    void calculation()
    {
        bool exit = false;
        int choose;
        while (!exit)
        {

            cout << "\nPlease enter firsr number : ";
            cin >> a;
            cout << "Please enter second number : ";
            cin >> b;
            cout << "1. Addition" << endl;
            cout << "2. Subtraction" << endl;
            cout << "3. Multiplication" << endl;
            cout << "4. Division" << endl;
            cout << "5. Exit" << endl;
            cout << "Please enter your choice : ";
            cin >> choose;
            switch (choose)
            {
            case 1:
                add(a, b);
                break;
            case 2:
                sub(a, b);
                break;
            case 3:
                multiply(a, b);
                break;
            case 4:
                divide(a, b);
                break;
            case 5:
                exit = true;
                system("clear");
                cout << "----------------------------------------------------------" << endl;
                cout << "\tThanks for using our Smart Calculator" << endl;
                cout << "----------------------------------------------------------" << endl;

                break;

            default:
                cout << "Please enter a valid choice " << endl;

                break;
            }
        }
    }
};
int main()
{
    myclass obj;
    obj.menu();
    return 0;
}
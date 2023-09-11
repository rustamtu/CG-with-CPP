#include <iostream>
#include <string.h>
using namespace std;

const int MAX_VALID_YR = 9999;
const int MIN_VALID_YR = 1800;
struct date
{
    int day;
    int month;
    int year;
    void read();
    void display();
    void validate();
    string getMonthDisplayName(int);
};
void date::read()
{
    cout << "Enter day: ";
    cin >> day;
    cout << "Enter month: ";
    cin >> month;
    cout << "Enter year: ";
    cin >> year;
}
void date::display()
{
    cout << "\n"
         << getMonthDisplayName(month) << "-" << day << "-" << year << endl;
}

void date::validate()
{
    if (MAX_VALID_YR <= year <= MIN_VALID_YR)
    {
        if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 0 && day <= 31)
            cout << "It is valid";
        else if (month == 4 || month == 6 || month == 9 || month == 11 && day > 0 && day <= 30)
            cout << "It is Valid";
        else if (month == 2)
        {
            if ((year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) && day > 0 && day <= 29)
                cout << "It is Valid";
            else if (day > 0 && day <= 28)
                cout << "It is Valid";
            else
                cout << "It is Invalid";
        }
        else
            cout << "It is Invalid";
    }
    else
        cout << "It is Invalid";
}

string date::getMonthDisplayName(int month)
{
    // char *mm = new char(100);
    // strcpy(mm, "January");
    // return mm;

    // char *arr = new char(100);
    // // arr = "safsdfgd";
    // strcpy(arr, "xxxx");
    // return arr;

    switch (month)
    {
    case 1:
        return "January";
    case 2:
        return "February";
    case 3:
        return "March";
    case 4:
        return "April";
    case 5:
        return "May";
    case 6:
        return "June";
    case 7:
        return "July";
    case 8:
        return "August";
    case 9:
        return "September";
    case 10:
        return "October";
    case 11:
        return "November";
    case 12:
        return "December";
    default:
        return NULL; // Invalid month
    }
}

int main()
{
    struct date d;
    d.read();
    d.validate();
    d.display();
    return 0;
}

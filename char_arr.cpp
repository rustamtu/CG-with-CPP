#include <iostream>
#include <cstring>
using namespace std;

char *testfunc()
{
    char *arr = new char(100);
    // arr = "safsdfgd";
    strcpy(arr, "xxxx");
    return arr;
}

int main()
{
    cout << testfunc();
}

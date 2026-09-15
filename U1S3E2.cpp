#include <iostream>

using namespace std;

int main()
{
    int number;

    cout << "Enter a number: ";
    cin >> number;

    if (number % 2 == 0)
    {
        if (number < 0)
        {
            cout << "Fail." << endl;
        }
        else
        {
            cout << "Success." << endl;
        }
    }
    else
    {
        if (number < 0)
        {
            cout << "Success." << endl;
        }
        else
        {
            cout << "Fail." << endl;
        }
    }

    return 0;
}
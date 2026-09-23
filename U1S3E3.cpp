#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

void datatype(string str)
{
    bool isNegative = (str[0] == '-');
    
    // Strip sign for easier digit counting and parsing
    string cleanStr = str;
    if (str[0] == '-' || str[0] == '+') 
    {
        cleanStr = str.substr(1);
    }


    size_t decimalPos = cleanStr.find('.'); // Check if it contains a decimal point 
    bool decimal = (decimalPos != string::npos); //it is a decimal if it is not equal to npos

    if (decimal)
    {
        if (cleanStr.length() - 1 <= 7) // Counts the total digits excluding the decimal point
        {
            cout << "Float" << endl;
        }
        else if (cleanStr.length() - 1 > 7 && cleanStr.length() - 1 < 14) 
        {
            cout << "Double" << endl;
        }
        else if (cleanStr.length() -1 >= 14)
        {
            cout << "Long Double" << endl;
        }
        return;
    }

    else if (cleanStr.length() == 1) 
    {
        cout << "Char" << endl;
        return;
    }
}


int main()
{
    string number;
    cout << "Enter a number: ";
    cin >> number;

    cout << "Data Type: ";
    datatype(number);
}
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
    if (str[0] == '-' || str[0] == '+')  // Check for negative or positive sign
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

    else if (cleanStr.length() == 1)  //if the length of the string is 1, it is a char
    {
        cout << "Char" << endl;
        return;
    }

    try // Convert to a large integer type to check bounds safely
    {
        long long value = stoll(str); // Convert string to long long

        if (isNegative) // Negative numbers and checks if the value is within each of the data type ranges
        {
            if (value >= SHRT_MIN)
            {
                cout << "Short" << endl;
            } 
            else if (value >= INT_MIN) 
            {
                cout << "Long" << endl;
            } 
            else 
            {
                cout << "Long long" << endl;
            }
        } 

        else 
        {
            // Positive numbers and checks if the value is within each of the data type ranges 
            if (value <= SHRT_MAX) 
            {
                cout << "Short" << endl;
            } 
            else if (value <= USHRT_MAX) 
            {
                cout << "Unsigned short" << endl;
            } 
            else if (value <= INT_MAX) 
            {
                cout << "Int" << endl;
            } 
            else if (value <= UINT_MAX) 
            {
                cout << "Unsigned int" << endl;
            }
            else 
            {
                cout << "unsigned long long" << endl;
            }
        }
    }

    catch (const out_of_range&) // The value is too large for long long
    {
        if (isNegative) 
        {
            cout << "long long" << endl;
        }
        else
        {
            cout << "unsigned long long" << endl;
        }
    }

    catch (const invalid_argument&) // The string is not a valid number
    {
        cout << "Invalid input" << endl;
    }
}    


int main()
{
    string number;
    cout << "Enter a number: ";
    cin >> number;

    cout << "Data Type: ";
    datatype(number);

    return 0;
}
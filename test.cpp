#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

void determineDataType(string str) 
{

    // Check for negative sign
    bool isNegative = (str[0] == '-');
    
    // Strip sign for easier digit counting and parsing
    string cleanStr = str;
    if (str[0] == '-' || str[0] == '+') 
    {
        cleanStr = str.substr(1);
    }

    // Check if it contains a decimal point
    size_t decimalPos = cleanStr.find('.');
    bool hasDecimal = (decimalPos != string::npos);

    if (hasDecimal) 
    {
        // Counts the total digits excluding the decimal point
        int totalDigits = cleanStr.length() - 1; 

        if (totalDigits <= 7) 
        {
            cout << "Float" << endl;
        } 
        else 
        {
            cout << "Double" << endl;
        }
    } 
    else 
    {
        // No Decimal
        if (cleanStr.length() == 1) 
        {
            cout << "Char" << endl;
            return;
        }

        try 
        {
            // Convert to a large integer type to check bounds safely
            long long value = stoll(str);

            if (isNegative) 
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
                // Positive numbers
                if (value <= SHRT_MAX) 
                {
                    cout << "Short" << endl;
                } 
                else if (value <= USHRT_MAX) {
                    cout << "Unsigned short" << endl;
                } 
                else if (value <= INT_MAX) 
                {
                    cout << "Long" << endl;
                } 
                else if (value <= UINT_MAX) 
                {
                    cout << "Unsigned int" << endl;
                }
                else 
                {
                    cout << "Unsigned long long" << endl;
                }
            }
        } 
        catch (const out_of_range&) // The value is too large for long long
        {
            // If it exceeds long long limits
            if (isNegative) 
            {
                cout << "Long long" << endl;
            } 
            else 
            {
                cout << "Unsigned long long" << endl;
            }
        } 
        catch (const invalid_argument&) 
        {
            cout << "Invalid number format" << endl;
        }
    }
}

int main() {
    string input;
    cout << "Enter a number: ";
    cin >> input;

    cout << "Determined Type: ";
    determineDataType(input);

    return 0;
}
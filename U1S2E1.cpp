#include <iostream>
#include <limits>
using namespace std;

int main()
{
    cout << "int min = " << numeric_limits<int>::min() << endl; // Shows the minimum value of specified data type
    cout << "int max = " << numeric_limits<int>::max() << endl; // Shows the maximum value of specified data type

    cout << "unsigned int min = " << numeric_limits<unsigned int>::min() << endl; //prints minimum value of unsigned int (usually 0)
    cout << "unsigned int max = " << numeric_limits<unsigned int>::max() << endl; //prints maximum value of unsigned int 

    cout << "short min = " << numeric_limits<short>::min() << endl; //prints minimum for signed short (negative)
    cout << "short max = " << numeric_limits<short>::max() << endl; //prints maximum for signed short (positive)

    cout << "unsigned short min = " << numeric_limits<unsigned short>::min() << endl; //prints minimum for unsigned short (0)
    cout << "unsigned short max = " << numeric_limits<unsigned short>::max() << endl; //prints maximum for unsigned short

    cout << "long min = " << numeric_limits<long>::min() << endl; //prints minimum for signed long (negative)
    cout << "long max = " << numeric_limits<long>::max() << endl; //prints maximum for signed long (positive)

    cout << "unsigned long min = " << numeric_limits<unsigned long>::min() << endl; //prints minimum for unsigned long (0)
    cout << "unsigned long max = " << numeric_limits<unsigned long>::max() << endl; //prints maximum for unsigned long

    return 0;
}
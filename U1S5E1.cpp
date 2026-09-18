//Create a program that displays the contents of a vector in reverse order. And displays their
//maximum and minimum elements

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> numbers = {1,2,3,4,5};

    cout << "Contents in reverse order: ";
    for (int i = numbers.size() - 1; i >= 0; i--)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;
}

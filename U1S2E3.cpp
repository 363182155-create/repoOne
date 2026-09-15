#include <iostream>
using namespace std;

int main()
{
    string name;
    string phoneNumber;
    char hand;
    int age;

    cout << "What is your name? ";
    getline(cin, name);

    cout << "What is your age? ";
    cin >> age;

    cout << "What is your phone number? ";
    cin >> phoneNumber;

    cout << "What is your handedness? (L, R, or B) ";
    cin >> hand;

    return 0;

}
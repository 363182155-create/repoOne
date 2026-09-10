#include <iostream>

using namespace std;

int main() {
    string firstname;
    string lastname; 

    cout << "Enter your first name: ";
    cin >> firstname;

    cout << "Enter your last name: ";
    cin >> lastname;

    cout << "Hello, " << firstname << " " << lastname << "!" << endl;

    return 0;
}
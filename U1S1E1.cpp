#include <iostream>

using namespace std;

int main() {
    string name; 
    int ticket;
    int price = rand() %51 + 50;

    char letters[] = {'A', 'B', 'C', 'D'};

    cout << "What is your name? " << endl;
    getline(cin, name);

    srand(time(0));
    ticket = rand() %200 + 1;

printf("|------------------------------------|\n")
printf("|Name: Bruce Banner |\n")
printf("|Section: A |\n")
printf("|Seat: 123 |\n")
printf("|Price: $83 |\n")
printf("|------------------------------------|\n")

    return 0;
}
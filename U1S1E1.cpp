#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    string name;
    int ticket;
    int price = rand() %51 + 50;
    
    char letters[] = {'A', 'B', 'C', 'D'};
    int index = rand() % 4;

    cout << "What is your name?" << endl;
    getline(cin, name);

    cout << "Hey there, " << name << "! How's it going?" << endl;

    srand(time(0)); // so it doesnt start at the same seed everytime (would print 42 everytime otherwise)
    ticket = rand() %200 + 1;



    cout << "|---------------|" << endl;
    cout << "|Name: " << name << "\t|" << endl;
    cout << "|Ticket: " << letters[index] << "\t|" << endl;
    cout << "|Seat: " << ticket << "\t|" << endl;
    cout << "|Price: $" << price << "\t|" << endl;
    cout << "|---------------|" << endl;

    return 0;
}
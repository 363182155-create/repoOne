#include <iostream>
#include <string>
#include <ctime>
#include <cstdio>
using namespace std;

int main()
{
    string name;
    int ticket;
    int price;
    char letters[] = {'A', 'B', 'C', 'D'};
    int index;
    index = rand() % 4;
    ticket = rand() % 200 + 1;
    price = rand() % 51 + 50;

    srand(time(0));

    cout << "What is your name? ";
    getline(cin, name);

    if (name.length() > 25)
    {
        name = name.substr(0, 25);
    }

    cout << "Hey there, " << name << "! How's it going?" << endl;

    cout << "|---------------------------|" << endl;
    printf("| %-25s |\n", name.c_str());
    printf("| Letter: %-1c                 |\n", letters[index]);
    printf("| Seat: %03d                 |\n", ticket);
    printf("| Price: $%2d                |\n", price);
    cout << "|---------------------------|" << endl;

    return 0;
}
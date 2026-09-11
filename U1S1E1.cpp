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

printf("|------------------------------------|\n");
printf("|%-25s |\n", name.c_str());
printf("|Section: %-1c                        |\n", letters[rand() % 4]);
printf("|Seat: %d |\n", ticket);
printf("|Price: $%d |\n", price);
printf("|------------------------------------|\n");

    return 0;
}
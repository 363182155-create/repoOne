#include <iostream>
using namespace std;

string word; 

int main()
{
    cout << "Enter a word: ";
    getline(cin, word);

    if (word.length() == 5)
    {
        cout << "The word is 5 letters long." << endl;
    }
    else
    {
        cout << "The word is not 5 letters long." << endl;
    }
    return 0;
}
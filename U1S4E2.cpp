#include <iostream>

using namespace std;

int main()
{
    string word;
    string palindrome = "";
    
    cout << "Enter a word (can be more then one): ";
    getline(cin, word);

    for (char c : word)
    {
        if (c != ' ')
        {
            palindrome += c;
        }
    }

    string reversed = palindrome;
    for (int i = 0; i < palindrome.length() / 2; i++)
    {
        swap(reversed[i], reversed[palindrome.length() - 1 - i]);
    }

    if (palindrome == reversed)
    {
        cout << "The word is a palindrome." << endl;
    }
    else
    {
        cout << "The word is not a palindrome." << endl;
    }

    return 0;
}
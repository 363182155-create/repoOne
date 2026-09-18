#include <iostream>

using namespace std;

int main()
{
    for (int i = 1; i <= 5; i++)
    { 
        for (int a = 1; a <= i ; a++)
        {    
            cout << '*';
        }
        cout << endl;
    }
    return 0;
}

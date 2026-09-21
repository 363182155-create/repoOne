#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    vector<int> numbers = {1, 2, 1, 3, 2};
    sort(numbers.begin(), numbers.end());
    
    for (int i = 1; i < numbers.size(); i++)
    {
        if (numbers[i] == numbers[i - 1])
        {
            cout << "There are " << count(numbers.begin(), numbers.end(), numbers[i]) << " duplicates of: " << numbers[i] << endl;
        }
    }   
}

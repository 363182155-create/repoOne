#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    vector<int> even = {2, 4, 6, 8, 10};
    vector<int> odd = {1, 3, 5, 7, 9};

    even.reserve(even.size() + odd.size());
    copy(odd.begin(), odd.end(), back_inserter(even));

    sort(even.begin(), even.end());

    for (int sort : even)
    {
        cout << sort << " ";
    }

return 0;
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void displayTasks(const vector<string>& tasks)
{
    cout << "+-- TODO LIST FOR TODAY --+  " << endl;

    for (const auto& task : tasks)
    {
        cout << "• " << task << endl;
    }
}

int main()
{

string tasks;
vector<string> taskList;

cout << "Enter your tasks (separated by commas): ";
getline(cin, tasks);

size_t start = 0;
size_t end = tasks.find(',');
while (end != string::npos)
{
    taskList.push_back(tasks.substr(start, end - start));
    start = end + 1;
    end = tasks.find(',', start);
}

taskList.push_back(tasks.substr(start));

displayTasks(taskList);

}
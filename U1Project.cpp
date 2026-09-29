#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>


using namespace std;

void displayTasks(const vector<string>& tasks)
{
    cout << "+-- TODO LIST FOR TODAY --+  " << endl;

    for (const auto& task : tasks)
    {
        cout << "• " << task << endl;
    }
}

void addTask(vector<string>& tasks, const string& task)
{
    tasks.push_back(task);
}

void removeTask(vector<string>& tasks, const string& task)
{
    auto remove = find(tasks.begin(), tasks.end(), task);
    if (remove != tasks.end())
    {
        tasks.erase(remove);
    }
}


int main()
{
    
int choice;
string tasks;
vector<string> taskList;
bool running = true;

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

//-----------------------------------------------------------------------------------------

while (running)
{
cout << "\nOptions: " << endl;
cout << "1. Add a task" << endl;
cout << "2. Remove a task" << endl;
cout << "3. Exit" << endl;

cin >> choice;
cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

    switch (choice)
    {
        case 1:
        {
            string newTask;
            cout << "\nEnter the task to add: ";
            getline(cin, newTask);
            addTask(taskList, newTask);
            break;
        }
        case 2:
        {
            string taskToRemove;
            cout << "\nEnter the task to remove: ";
            getline(cin, taskToRemove);
            removeTask(taskList, taskToRemove);
            break;
        }
    
        case 3:
        {
            running = false;
            cout << "You are done" << endl;
            break;
        }
    }
}

displayTasks(taskList);

}
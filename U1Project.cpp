#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <cctype>

using namespace std;

//====================================================================================

void displayTasks(const vector<string>& tasks)
{
    cout << "+-- TODO LIST FOR TODAY --+  " << endl;

    for (const auto& task : tasks)
    {
        cout << "• " << task << endl;
    }
}

//------------------------------------------------------------------------------------------

void addTask(vector<string>& tasks, const string& task)
{
    tasks.push_back(task);
}

//------------------------------------------------------------------------------------------

void removeTask(vector<string>& tasks, const string& task)
{
    auto remove = find(tasks.begin(), tasks.end(), task);
    if (remove != tasks.end())
    {
        tasks.erase(remove);
    }
}

//------------------------------------------------------------------------------------------

int main()
{
int choice;
string tasks;
vector<string> taskList;
bool running = true;

//------------------------------------------------------------------------------------------

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
cout << "3. Read Tasks" << endl;
cout << "4. Exit" << endl;
cout << "5. Sort Alphabetically" << endl;
cout << "6. Reset the list" << endl;

cin >> choice;
cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

//-----------------------------------------------------------------------------------

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

//------------------------------------------------------------------------------------

        case 2:
        {
            string taskToRemove;
            cout << "\nEnter the task to remove: ";
            getline(cin, taskToRemove);
            removeTask(taskList, taskToRemove);
            break;
        }
    
//------------------------------------------------------------------------------------

        case 3: //read tasks
        {
            displayTasks(taskList);
            break;
        }

//----------------------------------------------------------------------------------

        case 4: //end tasks
        {
            running = false;
            cout << "You are done" << endl;
            break;
        }

//----------------------------------------------------------------------------------

        case 5: //sort alphabetically
        {
            if (taskList.size() < 2)
            {
                cout << "List is already sorted or empty." << endl;
                break;
            }

            for (size_t i = 0; i < taskList.size(); i++)
            {
                for (size_t t = 0; t < taskList.size() - 1 - i; t++)
                {
                    string left = taskList[t];
                    string right = taskList[t + 1];

                    for (char& alpha : left) 
                    {
                        alpha = tolower(static_cast<unsigned char>(alpha));
                    }

                    for (char& alpha : right)
                    {
                        alpha = tolower(static_cast<unsigned char>(alpha));
                    }

                    if (left > right)
                    {
                        swap(taskList[t], taskList[t + 1]);
                    }
                }
            }

            displayTasks(taskList);
            break;
        }

//--------------------------------------------------------------------------------------

        case 6: //reset the list
        {
            taskList.clear();
            cout << "\nEnter your new tasks (separated by commas): ";
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
            break;
        }
    }
}

//------------------------------------------------------------------------------------------

displayTasks(taskList);

}
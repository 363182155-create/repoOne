#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <cctype>
#include <chrono>
#include <fstream>

using namespace std;

//====================================================================================

void displayTasks(const vector<string>& tasks) //Function to display tasks
{
    auto now = chrono::system_clock::now(); // Get the current time
    auto time = chrono::floor<chrono::seconds>(now); //Calculates the value as a readable time
    string red = "\033[1;31m";
    string reset = "\033[0m";
   
    cout << "\n+-- TODO LIST FOR TODAY --+  " << endl;
    cout << red << "Current Local Time: " << chrono::current_zone()->to_local(time) << "\n" << reset; //Sets timezone


    for (const auto& task : tasks)
    {
        cout << "• " << task << endl; //Displays the tasks in a bullet point format
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

void sortTasks(vector<string>& tasks) //alphabetically
{
    if (tasks.size() < 2)
    {
        cout << "List is already sorted or empty." << endl;
        return;
    }

    for (size_t i = 0; i < tasks.size(); i++)
    {
        for (size_t s = 0; s < tasks.size() - 1 - i; s++)
        {
            string left = tasks[s];
            string right = tasks[s + 1];

            for (int j = 0; j < left.length(); j++)
            {
                if (left[j] >= 'A' && left[j] <= 'Z')
                {
                    left[j] = left[j] + 32;
                }
            }

            for (int j = 0; j < right.length(); j++)
            {
                if (right[j] >= 'A' && right[j] <= 'Z')
                {
                    right[j] = right[j] + 32;
                }
            }

            if (left > right)
            {
                swap(tasks[s], tasks[s + 1]);
            }
        }
    }
}

//------------------------------------------------------------------------------------------

void sortTasksReverse(vector<string>& tasks) //reverse alphabetically
{
    if (tasks.size() < 2)
    {
        cout << "List is already sorted or empty." << endl;
        return;
    }

    for (size_t i = 0; i < tasks.size(); i++)
    {
        for (size_t s = 0; s < tasks.size() - 1 - i; s++)
        {
            string left = tasks[s];
            string right = tasks[s + 1];

            for (int j = 0; j < left.length(); j++)
            {
                if (left[j] >= 'A' && left[j] <= 'Z')
                {
                    left[j] = left[j] + 32;
                }
            }

            for (int j = 0; j < right.length(); j++)
            {
                if (right[j] >= 'A' && right[j] <= 'Z')
                {
                    right[j] = right[j] + 32;
                }
            }

            if (left < right)
            {
                swap(tasks[s], tasks[s + 1]);
            }
        }
    }
}

//------------------------------------------------------------------------------------------

void saveFile(const string& filename, const vector<string>& tasks)
{
    ofstream txtFile(filename); // ofstream is used to open the file to write in it
    if (txtFile.is_open())
    {
        for (const auto& entry : tasks)
        {
            txtFile << entry << "\n";
        }
        txtFile.close();
        cout << "List saved successfully to " << filename << "\n";
    }
    else
    {
        cout << "Error opening file for writing.\n";
    }
}

//------------------------------------------------------------------------------------------

void loadFile(vector<string>& tasks, const string& filename)
{
    ifstream inputFile(filename);
    if (!inputFile.is_open())
    {
        cout << "Error opening file for reading.\n";
        return;
    }

    tasks.clear();
    string line;
    while (getline(inputFile, line))
    {
        if (!line.empty())
        {
            tasks.push_back(line);
        }
    }

    inputFile.close();
    cout << "List loaded from " << filename << "\n";
}


//------------------------------------------------------------------------------------------

void addAndPriority(vector<string>& tasks)
{
    string task;

    cout << "\nEnter each task on a new line. Type 'Done' when finished.\n";

    while (true)
    {
        cout << "Task: ";
        getline(cin, task);

        if (task.empty())
        {
            continue;
        }

        while (!task.empty() && task[0] == ' ')
        {
            task.erase(0, 1);
        }

        while (!task.empty() && task[task.length() - 1] == ' ')
        {
            task.erase(task.length() - 1, 1);
        }

        if (task.empty())
        {
            continue;
        }

        string lowered = task;
        for (int i = 0; i < lowered.length(); i++)
        {
            if (lowered[i] >= 'A' && lowered[i] <= 'Z')
            {
                lowered[i] = lowered[i] + 32;
            }
        }

        if (lowered == "done")
        {
            break;
        }

        addTask(tasks, task);
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

addAndPriority(taskList);
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
cout << "6. Sort Reverse Alphabetically" << endl;
cout << "7. Save to File" << endl;
cout << "8. Load from File" << endl;
cout << "9. Reset the list" << endl;

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
            sortTasks(taskList);
            displayTasks(taskList);
            break;
        }

//----------------------------------------------------------------------------------

        case 6: //sort reverse alphabetically
        {
            sortTasksReverse(taskList);
            displayTasks(taskList);
            break;
        }

//--------------------------------------------------------------------------------------

        case 7: //save to file
        {
            string fileName;
            cout << "\nEnter a file name (for example: tasks.txt): ";
            getline(cin, fileName);

            if (fileName.find(".txt") == string::npos)
            {
                fileName += ".txt";
            }

            saveFile(fileName, taskList);
            break;
        }

//--------------------------------------------------------------------------------------

        case 8: //load from file
        {
            string fileName;
            cout << "\nEnter the file name to load (for example: tasks.txt): ";
            getline(cin, fileName);

            if (fileName.find(".txt") == string::npos)
            {
                fileName += ".txt";
            }

            loadFile(taskList, fileName);
            displayTasks(taskList);
            break;
        }

//--------------------------------------------------------------------------------------

        case 9: //reset the list
        {
            taskList.clear();
            addAndPriority(taskList);
            displayTasks(taskList);
            break;
        }
    }
}

//------------------------------------------------------------------------------------------

displayTasks(taskList);
}
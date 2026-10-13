#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <cctype>
#include <chrono>
using namespace std;


//====================================================================================


void displayTasks(const vector<string>& tasks)
{
    auto now = chrono::system_clock::now();
    auto time = chrono::floor<chrono::seconds>(now);
    string red = "\033[1;31m";
    string reset = "\033[0m";
   
    cout << "\n+-- TODO LIST FOR TODAY --+  " << endl;
    cout << red << "Current Local Time: " << chrono::current_zone()->to_local(time) << "\n" << reset;


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
                swap(tasks[s], tasks[s + 1]);
            }
        }
    }
}


//------------------------------------------------------------------------------------------


void sortTasksReverse(vector<string>& tasks)
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


            for (char& alpha : left)
            {
                alpha = tolower(static_cast<unsigned char>(alpha));
            }


            for (char& alpha : right)
            {
                alpha = tolower(static_cast<unsigned char>(alpha));
            }


            if (left < right)
            {
                swap(tasks[s], tasks[s + 1]);
            }
        }
    }
}


//------------------------------------------------------------------------------------------


// void saveFile(const vector<string>& filename, const string& tasks)
// {
//     ofstream txtFile(filename); // ofstream is used to open the file to write in it
//     if (txtFile.is_open())
//     {
//         for (const auto& entry : tasks)
//         {
//             txtFile << entry << "\n";
//         }
//         txtFile.close();
//         cout << "List saved successfully!\n";
//     }
//     else
//     {
//         cout << "Error opening file for writing.\n";
//     }
// }


//------------------------------------------------------------------------------------------


// void loadFile(vector<string>& tasks, const string& filename)
// {
   
// }


//------------------------------------------------------------------------------------------


void splitTasks(const string& input, vector<string>& taskList)
{
    taskList.clear();
    size_t start = 0;

    while (start <= input.size())
    {
        size_t end = input.find(',', start);
        if (end == string::npos)
        {
            end = input.size();
        }

        string task = input.substr(start, end - start);

        while (!task.empty() && isspace(static_cast<unsigned char>(task.front())))
        {
            task.erase(task.begin());
        }

        while (!task.empty() && isspace(static_cast<unsigned char>(task.back())))
        {
            task.pop_back();
        }

        if (!task.empty())
        {
            taskList.push_back(task);
        }

        if (end == input.size())
        {
            break;
        }

        start = end + 1;
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
splitTasks(tasks, taskList);
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


        }

//--------------------------------------------------------------------------------------

        // case 8: //load from file
        // {


        // }

//--------------------------------------------------------------------------------------

        case 9: //reset the list
        {
            taskList.clear();
            cout << "\nEnter your new tasks (separated by commas): ";
            getline(cin, tasks);
            splitTasks(tasks, taskList);
            displayTasks(taskList);
            break;
        }
    }
}

//------------------------------------------------------------------------------------------

displayTasks(taskList);
}


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <cctype>
#include <chrono>
#include <fstream>
#include <climits>

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
    tasks.push_back(task); // Adds a new task to the end of the vector
}

//------------------------------------------------------------------------------------------

void removeTask(vector<string>& tasks, const string& task)
{
    auto remove = find(tasks.begin(), tasks.end(), task); // Finds the task in the vector
    if (remove != tasks.end()) // If the task is found, remove it
    {
        tasks.erase(remove); // Removes the task from the vector
    }
}

//------------------------------------------------------------------------------------------

string toLowerCopy(string value) // Function to convert a string to lowercase
{
    transform(value.begin(), value.end(), value.begin(), [](unsigned char ch) { return static_cast<char>(tolower(ch)); }); // Converts each character to lowercase
    return value;
}

//------------------------------------------------------------------------------------------

string trim(const string& value) // Function to remove leading and trailing whitespace
{
    const size_t start = value.find_first_not_of(" \t\r\n"); // Finds the first non-whitespace character
    if (start == string::npos) // If the string is empty or contains only whitespace
    {
        return ""; // Return an empty string
    }
//find last not of is a string function that returns the position of the first cahracter

    const size_t end = value.find_last_not_of(" \t\r\n");  
    return value.substr(start, end - start + 1);
}

//------------------------------------------------------------------------------------------

string ensureTxtExtension(const string& fileName)
{
    if (fileName.find(".txt") == string::npos) //finds file name and adds ".txt" if it does not exist
    {
        return fileName + ".txt"; //returns the file name with ".txt" extension
    }

    return fileName; //returns the file name as is if it already has ".txt" extension
}

//------------------------------------------------------------------------------------------

void sortTasks(vector<string>& tasks) //alphabetically
{
    if (tasks.size() < 2) // If the list has less than 2 tasks, it is already sorted or empty
    {
        cout << "List is already sorted or empty." << endl; 
        return;
    }

    for (size_t i = 0; i < tasks.size(); i++) // Outer loop for the number of passes
    {
        for (size_t s = 0; s < tasks.size() - 1 - i; s++) //compares each task with the next one in the list
        {
            string left = toLowerCopy(tasks[s]); // Converts the current task to lowercase to compare 
            string right = toLowerCopy(tasks[s + 1]); //convers the next task to lowercase to compare

            if (left > right) 
            {
                swap(tasks[s], tasks[s + 1]); //switches the two tasks if the current task is greater than the next one
            }
        }
    }
}

//------------------------------------------------------------------------------------------

void sortTasksReverse(vector<string>& tasks) //reverse alphabetically
{
    if (tasks.size() < 2) //if the list has less than 2 tasks, it is already sorted or empty
    {
        cout << "List is already sorted or empty." << endl;
        return;
    }

    for (size_t i = 0; i < tasks.size(); i++) // Outer loop for the number of passes
    {
        for (size_t s = 0; s < tasks.size() - 1 - i; s++) //compares each task with the next one in the list
        {
            string left = toLowerCopy(tasks[s]); 
            string right = toLowerCopy(tasks[s + 1]);

            if (left < right) // if the next task is greater than the current task, swap them to sort in reverse order
            {
                swap(tasks[s], tasks[s + 1]); //switches the two tasks if the current task is less than the next one
            }
        }
    }
}

//------------------------------------------------------------------------------------------

void saveFile(const string& filename, const vector<string>& tasks) //save file function
{
    ofstream txtFile(filename); // ofstream is used to open the file to write in it

    if (txtFile.is_open()) 
    {
        for (const auto& entry : tasks)
        {
            txtFile << entry << "\n"; //allows the user to enter a task and creates a new line for each task in the file
        }

        txtFile.close();
        cout << "List saved successfully to " << filename << "\n"; //displays a message to the user that the list has been saved successfully
    }
    else
    {
        cout << "Error opening file for writing.\n"; 
    }
}

//------------------------------------------------------------------------------------------

void loadFile(vector<string>& tasks, const string& filename)
{
    string line;
    ifstream inputFile(filename);

    if (!inputFile.is_open()) //checks if the file is open and exists, if not it displays an error message and returns
    {
        cout << "Error opening file for reading.\n";
        return;
    }

    tasks.clear(); //clears the current list of tasks before loading the new list from the file

    while (getline(inputFile, line)) //reads each line from the file and adds it to the list of tasks
    {
        if (!line.empty()) //checks if the line is not empty before adding it to the list
        {
            tasks.push_back(line); //adds the line to the list of tasks
        }
    }

    inputFile.close();
    cout << "List loaded from " << filename << "\n";
}


//------------------------------------------------------------------------------------------

int getPriority() //priority function that prompts the user to enter a priority number and validates the input
{
    string input;
    int number;

    while (true)
    {
        cout << "Priority number: ";
        getline(cin, input);

        try
        {
            number = stoi(input); // Converts the input string to an integer

            if (number >= 0) //if the number is 0 or greater, it returns the number as a valid priority
            {
                return number;
            }

            cout << "Please enter a number that is 0 or bigger.\n";
        }
        catch (const invalid_argument&) // Catches the exception if the input is not a valid integer
        {
            cout << "Please enter a valid number.\n";
        }
    }
}

//------------------------------------------------------------------------------------------

int taskNumber(const string& task)
{
    size_t start = task.find('[');
    size_t end = task.find(']');

    if (start == string::npos || end == string::npos || end <= start)
    {
        return INT_MAX; // Return a large number if the format is incorrect
    }

    string value = task.substr(start + 1, end - start - 1);
    return stoi(value);
}

//------------------------------------------------------------------------------------------

string taskName(const string& task)
{
    size_t end = task.find(']');

    if (end == string::npos)
    {
        return task;
    }

    return task.substr(end + 2);
}

//------------------------------------------------------------------------------------------

void sortByPriority(vector<string>& tasks)
{
    if (tasks.size() < 2)
    {
        return;
    }

    for (int i = 0; i < tasks.size() - 1; i++)
    {
        for (int j = 0; j < tasks.size() - 1 - i; j++)
        {
            int leftNumber = taskNumber(tasks[j]);
            int rightNumber = taskNumber(tasks[j + 1]);

            string leftName = taskName(tasks[j]);
            string rightName = taskName(tasks[j + 1]);

            for (char& ch : leftName)
            {
                ch = tolower(ch);
            }

            for (char& ch : rightName)
            {
                ch = tolower(ch);
            }

            if (leftNumber > rightNumber || (leftNumber == rightNumber && leftName > rightName))
            {
                swap(tasks[j], tasks[j + 1]);
            }
        }
    }

    for (int i = 0; i < tasks.size(); i++)
    {
        tasks[i] = "[" + to_string(i + 1) + "] " + taskName(tasks[i]);
    }
}

//------------------------------------------------------------------------------------------

void sortTasksByPriority(vector<string>& tasks)
{
    sortByPriority(tasks); 
}

//------------------------------------------------------------------------------------------

void addAndPriority(vector<string>& tasks)
{
    string task;
    int priority;

    cout << "\nEnter each task on a new line. Type 'Done' when finished.\n";

    while (true)
    {
        cout << "Task: ";
        getline(cin, task);
        task = trim(task);
        priority = getPriority();
        
        if (task.empty())
        {
            continue;
        }

        if (toLowerCopy(task) == "done")
        {
            break;
        }


        addTask(tasks, "[" + to_string(priority) + "] " + task);
    }
}

//------------------------------------------------------------------------------------------

int main()
{
    int choice;
    bool running = true;
    vector<string> taskList;

//------------------------------------------------------------------------------------------

    cout << "Welcome to your To-Do List!\n";

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
        cout << "10. Sort by Priority" << endl;

        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

//-----------------------------------------------------------------------------------

        switch (choice)
        {
            case 1:
            {
                string newTask;
                int priority;
                priority = getPriority();

                cout << "\nEnter the task to add: ";
                getline(cin, newTask);
                newTask = trim(newTask);

                if (newTask.empty())
                {
                    break;
                }

                if (toLowerCopy(newTask) == "done")
                {
                    break;
                }


                addTask(taskList, "[" + to_string(priority) + "] " + newTask);
                break;
            }

            //------------------------------------------------------------------------------------

            case 2:
            {
                string taskToRemove;

                cout << "\nEnter the task to remove: ";
                getline(cin, taskToRemove);
                removeTask(taskList, trim(taskToRemove));
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
                saveFile(ensureTxtExtension(fileName), taskList);
                break;
            }

//--------------------------------------------------------------------------------------

            case 8: //load from file
            {
                string fileName;
                cout << "\nEnter the file name to load (for example: tasks.txt): ";
                getline(cin, fileName);
                loadFile(taskList, ensureTxtExtension(fileName));
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

//--------------------------------------------------------------------------------------

            case 10: //sort by priority
            {
                sortTasksByPriority(taskList);
                displayTasks(taskList);
                break;
            }
        }
    }

//------------------------------------------------------------------------------------------

    displayTasks(taskList);
}
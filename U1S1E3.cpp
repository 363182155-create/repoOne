#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    string name;
    int animals;
    int currentYear;
    int projectedYear;

    cout << "What is your favorite animal? ";
    getline(cin, name);

    cout << "How many of these animals do you have? ";
    cin >> animals;

    cout << "What is the current year? ";
    cin >> currentYear;

    cout << "What year would you like to project to? ";
    cin >> projectedYear;

    int population = projectedYear - currentYear;
    int projectedPopulation = animals * pow(2, population);

    cout << "Type of animal: " << name << endl;
    cout << "Starting Amount: " << animals << endl;
    cout << "Current Year: " << currentYear << endl;
    cout << "Projected Year: " << projectedYear << endl;
    cout << "Projected Population: " << projectedPopulation << endl;


}
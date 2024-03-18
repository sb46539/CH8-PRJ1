// This program collets data for marathon runners such as names, average miles, and total miles in a text file. It reads the data and runs the necessary calculations.
// It displays a table with name, total miles, and average miles.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const int numRunners = 5;
const int numDays = 7;

// preconds: names and miles arrays are allocated, postconds: reads runner data from text file into arrays
void readRunnerData(string names[], float miles[][numDays]) {
    ifstream inputFile("C:/Users/sb0s/source/repos/runners.txt");

    for (int i = 0; i < numRunners; i++) {
        inputFile >> names[i];
        for (int j = 0; j < numDays; j++) {
            inputFile >> miles[i][j];
        }
    }

    inputFile.close();
}
// preconds: names, miles, total, avg arrays are allocated, postconds: calculates total and average miles
void calculateTotal(const string names[], const float miles[][numDays], float total[], float avg[]) {
    for (int i = 0; i < numRunners; i++) {
        total[i] = 0;
        for (int j = 0; j < numDays; j++) {
            total[i] += miles[i][j];
        }
        avg[i] = total[i] / numDays;
    }
}
// preconds: names, miles, total, avg arrays are allocated, postconds: prints a formatted table displaying runner data
void printRunnerData(const string names[], const float miles[][numDays], const float total[], const float avg[]) {
    cout << setw(15) << left << "Runner's name";
    cout << setw(15) << right << "Total miles";
    cout << setw(15) << right << "Average miles" << endl;
    cout << setfill('-') << setw(45) << "-" << setfill(' ') << endl;

    for (int i = 0; i < numRunners; i++) {
        cout << setw(15) << left << names[i];
        cout << setw(15) << right << fixed << setprecision(2) << total[i];
        cout << setw(15) << right << fixed << setprecision(2) << avg[i] << endl;
    }
}

int main() {
    string runnerNames[numRunners];
    float milesRun[numRunners][numDays];
    float totalMiles[numRunners];
    float avgMiles[numRunners];

 
    readRunnerData(runnerNames, milesRun);
    calculateTotal(runnerNames, milesRun, totalMiles, avgMiles);
    printRunnerData(runnerNames, milesRun, totalMiles, avgMiles);

    return 0;
}

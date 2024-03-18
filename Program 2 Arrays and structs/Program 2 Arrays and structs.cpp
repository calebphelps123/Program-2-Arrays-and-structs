// Program 2 Arrays and structs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <iomanip> // For setw()

using namespace std;

const int NUM_RUNNERS = 5;
const int NUM_DAYS = 7;

// Struct to store runner information
struct Runner {
    string name;
    int miles[NUM_DAYS];
    int totalMiles;
    double avgMiles;
};

// Function to read and store runner data
void readData(Runner runners[]) {
    cout << "Enter data for " << NUM_RUNNERS << " runners:" << endl;
    for (int i = 0; i < NUM_RUNNERS; ++i) {
        cout << "Runner " << i + 1 << " name: ";
        cin >> runners[i].name;
        cout << "Enter miles run for each day of the week:" << endl;
        for (int j = 0; j < NUM_DAYS; ++j) {
            cout << "Day " << j + 1 << ": ";
            cin >> runners[i].miles[j];
        }
    }
}

// Function to calculate total miles and average miles
void calculateTotals(Runner runners[]) {
    for (int i = 0; i < NUM_RUNNERS; ++i) {
        runners[i].totalMiles = 0;
        for (int j = 0; j < NUM_DAYS; ++j) {
            runners[i].totalMiles += runners[i].miles[j];
        }
        runners[i].avgMiles = static_cast<double>(runners[i].totalMiles) / NUM_DAYS;
    }
}

// Function to display the results
void displayResults(const Runner runners[]) {
    cout << setw(15) << "Runner Name";
    for (int j = 0; j < NUM_DAYS; ++j) {
        cout << setw(10) << "Day " << j + 1;
    }
    cout << setw(15) << "Total Miles" << setw(15) << "Avg Miles" << endl;

    for (int i = 0; i < NUM_RUNNERS; ++i) {
        cout << setw(15) << runners[i].name;
        for (int j = 0; j < NUM_DAYS; ++j) {
            cout << setw(10) << runners[i].miles[j];
        }
        cout << setw(15) << runners[i].totalMiles << setw(15) << fixed << setprecision(2) << runners[i].avgMiles << endl;
    }
}

int main() {
    Runner runners[NUM_RUNNERS];

    readData(runners);
    calculateTotals(runners);
    displayResults(runners);

    return 0;
}
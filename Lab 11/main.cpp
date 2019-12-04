//  main.cpp
//  Lab 11
//  Created by Michael Wallerius on 12/4/19.
//  Code::Blocks on Windows 10

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>

using namespace std;

void sortArray(int studentIDArray[]);
void printFirstFive(int studentIDArray[]);
void printLastFive(int studentIDArray[]);
bool searchArray(int studentIDArray[], int searchValue);

const int SIZE = 750;
const int SIDS = 50;

int main(){
    string allValuesArray[SIZE];
    int studentIDArray[SIDS];

    ifstream input("ass6data.txt");
    if (!input.is_open()){
        exit(EXIT_FAILURE);
    }

    for (int idx = 0; idx < 750; idx++){
        input >> allValuesArray[idx];
    }

    int valueInterval = 0;
    for (int idx = 0; idx < 50; idx++){
        studentIDArray[idx] = stoi(allValuesArray[valueInterval]);
        valueInterval += 15;
    }

    sortArray(studentIDArray);
    printFirstFive(studentIDArray);
    printLastFive(studentIDArray);

    int searchFor = 1;
    while(searchFor != 0){
        cout << "Enter a student ID to search for. (0 to exit) ";
        cin >> searchFor;
        if (searchFor == 0){
            break;
        }
        else if (searchArray(studentIDArray, searchFor) == true){
            cout << searchFor << " is a valid student ID." << endl;
        }
        else {
            cout << searchFor << " is not a valid student ID." << endl;
        }

    }
}

void sortArray(int studentIDArray[]){
    sort(studentIDArray, studentIDArray + SIDS);
}

void printFirstFive(int studentIDArray[]){
    for (int idx = 0; idx < 5; idx++){
        cout << setw(8) << setfill('0') << studentIDArray[idx] << endl;
    }
}

void printLastFive(int studentIDArray[]){
    for (int idx = 45; idx < 50; idx++){
        cout << setw(8) << setfill('0') << studentIDArray[idx] << endl;
    }
}

bool searchArray(int studentIDArray[], int searchFor){
    for (int idx = 0; idx < 50; idx++){
        if (searchFor == studentIDArray[idx])
        {
            return true;
        }
    }
    return false;
}

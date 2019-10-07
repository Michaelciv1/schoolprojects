//  main.cpp
//  Assignment 2
//  Created by Michael Wallerius on 9/28/19.
//  Xcode on Mac OS Mojave

#include <iostream>
using namespace std;

int main()
{
    int apoints, epoints, mpoints, fpoints, clpoints;
    float total, percent;
    string fname, lname;
    
    cout << "Enter your first name => ";
    cin >> fname;
    cout << "Enter your last name => ";
    cin >> lname;
    cout << "Enter the total assignment points => ";
    cin >> apoints;
    cout << "Enter the total exercise points => ";
    cin >> epoints;
    cout << "Enter the total midterm points => ";
    cin >> mpoints;
    cout << "Enter the total final points => ";
    cin >> fpoints;
    cout << "Enter the total CodeLab points: ";
    cin >> clpoints;
    cout << endl;
    
    total = apoints + epoints + mpoints + fpoints + clpoints;
    percent = (total/400) * 100;
    
    
    cout << fname << " " << lname << "'s grade points" << endl;
    cout << "Assigments: " << apoints << endl;
    cout << "Exercises:  " << epoints << endl;
    cout << "Midterm:    " << mpoints << endl;
    cout << "Final:      " << fpoints << endl;
    cout << "CodeLab:    " << clpoints << endl;
    cout << "            ---" << endl;
    cout << "Total:      " << total << endl;
    cout << "Percent:    " << percent << "%" << endl;
}

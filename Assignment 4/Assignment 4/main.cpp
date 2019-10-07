//  main.cpp
//  Assignment 4
//  Created by Michael Wallerius on 10/5/19.
//  Xcode on OS X Mojave

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    unsigned short epoints, mpoints, fpoints, apoints, total;
    const int TOTAL_POINTS = 400;
    float percent;
    
    unsigned short points [11];
    
    cout << "Enter assignment 1 points "; cin >> points[0];
    cout << "Enter assignment 2 points "; cin >> points[1];
    cout << "Enter assignment 3 points "; cin >> points[2];
    cout << "Enter assignment 4 points "; cin >> points[3];
    cout << "Enter assignment 5 points "; cin >> points[4];
    cout << "Enter assignment 6 points "; cin >> points[5];
    cout << "Enter assignment 7 points "; cin >> points[6];
    cout << "Enter assignment 8 points "; cin >> points[7];
    cout << "Enter assignment 9 points "; cin >> points[8];
    cout << "Enter assignment 10 points "; cin >> points[9];
    cout << "Enter assignment 11 points "; cin >> points[10];
    cout << "Enter lab exercise points "; cin >> epoints;
    cout << "Enter midterm points "; cin >> mpoints;
    cout << "Enter final points "; cin >> fpoints;
    
    int lowest = points[0];
    for (int i = 1; i < 11; i++){
        if (points[i] < lowest){
            lowest = points[i];
        }
    }
    cout << endl;
    cout << "Assignment Grades:  ";
    for (int i = 0; i < 11; i++){
        cout << points[i] << setw(4);
    }
    cout << endl;
    
    int a,sum;
    sum = 0;
    
    for (a=0; a<11; a++)
    {
        sum += points[a];
    }
    
    apoints = sum - lowest;
    total = apoints + epoints + mpoints + fpoints;
    
    cout << "Assignment Points: " << apoints << endl;
    cout << "Lab Exercise:       " << epoints << endl;
    cout << "Midterm:            " << mpoints << endl;
    cout << "Final:              " << fpoints << endl;
    cout << "Total Points:      " << total << endl;
    
    percent = (static_cast<float>(total)/static_cast<float>(TOTAL_POINTS)) * 100;
    
    cout << "Percent of total:   " << fixed << setprecision(0) << percent << "%" << endl;
    
    char msg = 0;
    
    if (percent >= 89.5)
    {
        if (percent < 92)
        {
            msg = 1;
        }
        else if (percent >= 97.5)
        {
            msg = 2;
        }
        else {
            msg = 3;
        }
    }
    else if (percent >= 79.5)
    {
        if (percent < 82)
        {
            msg = 4;
        }
        if (percent >= 87.5)
        {
            msg = 5;
        }
        else {
            msg = 6;
        }
    }
    else if (percent >= 69.5)
    {
        if (percent < 72)
        {
            msg = 7;
        }
        else if (percent >= 77.5)
        {
            msg = 8;
        }
        else {
            msg = 9;
        }
    }
    else if (percent >= 59.5)
    {
        if (percent < 62)
        {
            msg = 10;
        }
        else if (percent >= 67.5)
        {
            msg = 11;
        }
        else {
            msg = 12;
        }
    }
    else if (percent < 59) {
        msg = 13;
    }
    
    switch (msg){
        case 1:
            cout << "Grade: A-" << endl;
            cout << "Excellent work" << endl;
            break;
        case 2:
            cout << "Grade: A+" << endl;
            cout << "Excellent work" << endl;
            break;
        case 3:
            cout << "Grade: A" << endl;
            cout << "Excellent work" << endl;
            break;
        case 4:
            cout << "Grade: B-" << endl;
            cout << "Not bad!" << endl;
            break;
        case 5:
            cout << "Grade: B+" << endl;
            cout << "Not bad!" << endl;
            break;
        case 6:
            cout << "Grade: B" << endl;
            cout << "Not bad!" << endl;
            break;
        case 7:
            cout << "Grade: C-" << endl;
            cout << "Not bad!" << endl;
            break;
        case 8:
            cout << "Grade: C+" << endl;
            cout << "Not bad!" << endl;
            break;
        case 9:
            cout << "Grade: C" << endl;
            cout << "Not bad!" << endl;
            break;
        case 10:
            cout << "Grade: D-" << endl;
            cout << "You better try again" << endl;
            break;
        case 11:
            cout << "Grade: D+" << endl;
            cout << "You better try again!" << endl;
            break;
        case 12:
            cout << "Grade: D" << endl;
            cout << "You better try again" << endl;
            break;
        case 13:
            cout << "Grade: F" << endl;
            cout << "You better try again" << endl;
            break;
    }
        
}

//  main.cpp
//  Assignment 6
//  Created by Michael Wallerius on 10/7/19.
//  Copyright © 2019 Michael Wallerius. All rights reserved.

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream my_input_file("ass6data.txt");
    ofstream my_output_file("studentreport.txt");
    
    const int TOTAL_POSSIBLE = 400;
    float percent;
    string sid; // I realized if you make this an int, the leading zeros will not be read
    int mpoints, fpoints, labpoints, apointsTotal, totalPoints;
    int numberOfA = 0, numberOfB = 0, numberOfC = 0, numberOfD = 0, numberOfF = 0, line = 0;
    int apoints[11];
    
    my_output_file << "Student" << "   " << "-----" << "   " << "Assignment Grades" << "  " << "-----" << "  " <<
    "Ass" << "  " << "Mid" << "  " << "Fin" << " " << "LEx" << " " << "Total" << "  " << "Pct" << " " << "Gr" << endl; // First line of headers
    my_output_file << "--------" << "  ";
    for (int f=0; f<11;f++){
        my_output_file << "-- ";
    }
    my_output_file << " " << "---" << "  " << "---" << "  " << "---" << " " << "--- " << "-----" << "  " << "---" << " " << "--" << endl; //Second line of headers
    
    if (!my_input_file.is_open() || !my_output_file.is_open()){
        exit(EXIT_FAILURE);
    }
    
    while (line < 50) { //initally attempted to do this loop with while (my_input_file) but it duplicated the final line, messing up the number of letter grades.
        my_input_file >> sid;
        my_output_file << sid << "  ";
        
        for (int i = 0; i < 11; i++){
            my_input_file >> apoints[i];
            my_output_file << setw(2) << right << apoints[i] << " ";
        }
        
        int lowest = apoints[0]; //reused from assignment 4 to determine lowest value in the array
        for (int i = 1; i < 11; i++){
            if (apoints[i] < lowest){
                lowest = apoints[i];
            }
        }
        
        my_output_file << " ";
        
        int a,sum;
        sum = 0;
        
        for (a=0; a<11; a++) //Determines total points from all elevent assignments
        {
            sum += apoints[a];
        }
        
        apointsTotal = sum - lowest;//Subtracts lowest to give actual assignment total
        
        my_output_file << apointsTotal << " ";
        
        my_input_file >> mpoints >> fpoints >> labpoints;
        my_output_file << "  " << setw(2) << right << mpoints << "   " << setw(2) << right << fpoints << "  " << setw(2) << right << labpoints;
        
        totalPoints = apointsTotal + mpoints + fpoints + labpoints;
        
        my_output_file << setw(6) << right << totalPoints;
        
        percent = ((static_cast<float>(totalPoints))/(static_cast<float>(TOTAL_POSSIBLE)))*100;
        
        my_output_file << setw(5) << right << setprecision(2) << percent << " ";
        
        char msg = 0; //Resued from assignment 4 to determine letter grade
        
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
                my_output_file << setw(2) << left << "A-" << endl;
                numberOfA += 1;
                break;
            case 2:
                my_output_file << setw(2) << left << "A+" << endl;
                numberOfA += 1;
                break;
            case 3:
                my_output_file << setw(2) << left << "A" << endl;
                numberOfA += 1;
                break;
            case 4:
                my_output_file << setw(2) << left << "B-" << endl;
                numberOfB += 1;
                break;
            case 5:
                my_output_file << setw(2) << left << "B+" << endl;
                numberOfB += 1;
                break;
            case 6:
                my_output_file << setw(2) << left << "B" << endl;
                numberOfB += 1;
                break;
            case 7:
                my_output_file << setw(2) << left << "C-" << endl;
                numberOfC += 1;
                break;
            case 8:
                my_output_file << setw(2) << left << "C+" << endl;
                numberOfC += 1;
                break;
            case 9:
                my_output_file << setw(2) << left << "C" << endl;
                numberOfC += 1;
                break;
            case 10:
                my_output_file << setw(2) << left << "D-" << endl;
                numberOfD += 1;
                break;
            case 11:
                my_output_file << setw(2) << left << "D+" << endl;
                numberOfD += 1;
                break;
            case 12:
                my_output_file << setw(2) << left << "D" << endl;
                numberOfD += 1;
                break;
            case 13:
                my_output_file << setw(2) << left << "F" << endl;
                numberOfF += 1;
                break;
        }
        line += 1;
    } // end of loop
    cout << "The number of A's = " << numberOfA << endl; // Final console output
    cout << "The number of B's = " << numberOfB << endl;
    cout << "The number of C's = " << numberOfC << endl;
    cout << "The number of D's = " << numberOfD << endl;
    cout << "The number of F's = " << numberOfF << endl;
}

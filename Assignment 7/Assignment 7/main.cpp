//  main.cpp
//  Assignment 7
//  Created by Michael Wallerius on 10/7/19.
//  Xcode on macOS Catalina

#include <iostream>
#include <fstream>

using namespace std;

ifstream my_input_file("ass7data.txt");
ofstream my_output_file("studentreport.txt");
ofstream my_program_file("programreport.txt");


int assignmentArray[11];
const int SIZE = 100;
const int TOTAL_POSSIBLE = 400;
string IDarray[SIZE];
int pointsArray[SIZE];
int mpoints, fpoints, labpoints, apoints, total, num, num2, x = 0;
float percent, numberOfStudents, globalTotal, globalPercentage;

string getStudentID();
int studentScores();
void totalScore();
void calculatePercentage();
void calculateGrade();
void output();

int main() {
    if (!my_input_file.is_open() || !my_output_file.is_open() || !my_program_file.is_open()){
        exit(EXIT_FAILURE);
    }
    
    my_output_file << "Student" << "   " << "-----" << "   " << "Assignment Grades" << "  " << "-----" << "  " <<
    "Ass" << "  " << "Mid" << "  " << "Fin" << " " << "LEx" << " " << "Total" << "  " << "Pct" << " " << "Gr" << endl; // First line of headers
    my_output_file << "--------" << "  ";
    for (int f=0; f<11;f++){
        my_output_file << "-- ";
    }
    my_output_file << " " << "---" << "  " << "---" << "  " << "---" << " " << "--- " << "-----" << "  " << "---" << " " << "--" << endl; //Second line of headers
    
    while (my_input_file.good()) {
        my_output_file << getStudentID() << "  ";
        if( my_input_file.eof() ) break; //prevents the program from duplicating the last line twice
        my_output_file << studentScores() << " ";
        totalScore();
        calculatePercentage();
        calculateGrade();
        x += 1;
    }
    int highest = 0;
    int lowest = 1000;
    for (int i=0; i < x; i++)
    {
        if (pointsArray[i] > highest){
            highest = pointsArray[i];
            num = i;
        }
        if(pointsArray[i] < lowest)
        {
            lowest = pointsArray[i];
            num2 = i;
        }
    }
    output();
}

string getStudentID(){
    string sid;
    my_input_file >> sid;
    IDarray[x] = sid;
    return sid;
}

int studentScores(){
    for (int i = 0; i < 11; i++){
        my_input_file >> assignmentArray[i];
        my_output_file << setw(2) << right << assignmentArray[i] << " ";
    }
    int sum;
    sum = 0;
    
    for (int a=0; a<11; a++){
        sum += assignmentArray[a];
    }
    int lowest = assignmentArray[0]; //reused from assignment 4 to determine lowest value in the array
    for (int i = 1; i < 11; i++){
        if (assignmentArray[i] < lowest){
            lowest = assignmentArray[i];
        }
    }
    my_output_file << " ";
    apoints = sum-lowest;
    numberOfStudents += 1;
    return apoints;
}

void totalScore(){
    my_input_file >> mpoints >> fpoints >> labpoints;
    my_output_file << "  " << setw(2) << right << mpoints << "   " << setw(2) << right << fpoints << "  " << setw(2) << right << labpoints;
    total = apoints + mpoints + fpoints + labpoints;
    my_output_file << setw(6) << right << total;
    globalTotal += total;
    pointsArray[x] = total;
    
}

void calculatePercentage(){
    percent = ((static_cast<float>(total))/(static_cast<float>(TOTAL_POSSIBLE)))*100;
    globalPercentage += percent;
    my_output_file << setw(5) << right << setprecision(2) << percent << " ";
}

void calculateGrade(){
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
        else if (percent >= 87.5)
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
            break;
        case 2:
            my_output_file << setw(2) << left << "A+" << endl;
            break;
        case 3:
            my_output_file << setw(2) << left << "A" << endl;
            break;
        case 4:
            my_output_file << setw(2) << left << "B-" << endl;
            break;
        case 5:
            my_output_file << setw(2) << left << "B+" << endl;
            break;
        case 6:
            my_output_file << setw(2) << left << "B" << endl;
            break;
        case 7:
            my_output_file << setw(2) << left << "C-" << endl;
            break;
        case 8:
            my_output_file << setw(2) << left << "C+" << endl;
            break;
        case 9:
            my_output_file << setw(2) << left << "C" << endl;
            break;
        case 10:
            my_output_file << setw(2) << left << "D-" << endl;
            break;
        case 11:
            my_output_file << setw(2) << left << "D+" << endl;
            break;
        case 12:
            my_output_file << setw(2) << left << "D" << endl;
            break;
        case 13:
            my_output_file << setw(2) << left << "F" << endl;
            break;
    }
}

void output(){
    my_program_file << "Number of students = " << numberOfStudents << endl;
    float averagePoints = globalTotal/numberOfStudents;
    my_program_file << "The average total points = " << setprecision(4) << averagePoints << endl;
    float averagePercentage = globalPercentage/numberOfStudents;
    my_program_file << "The average percent total = " << setprecision (3) << averagePercentage << "%" << endl;
    my_program_file << "Highest grade: ID=" << IDarray[num] << "  Points=" << pointsArray[num] << "  Percent=" << pointsArray[num]/(TOTAL_POSSIBLE*1.0)*100 << "%" << endl;
    my_program_file << "Lowest grade: ID=" << IDarray[num2] << "  Points=" << pointsArray[num2] << "  Percent=" << pointsArray[num2]/(TOTAL_POSSIBLE*1.0)*100 << "%" << endl;
}

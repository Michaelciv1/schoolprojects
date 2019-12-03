//  main.cpp
//  Assignment 10
//  Created by Michael Wallerius on 12/2/19.
//  Copyright © 2019 Michael Wallerius. All rights reserved.

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <sstream>

using namespace std;

const int MAX_SIZE = 1000;
const int NUM_FIELDS_PER_LINE = 7;

int upDays();
void downDays();
void maxClose();
void avgClose();


int main() {
    string stockName("CAT");
    string fileName = stockName + string(".csv");
    
    ifstream input(fileName.c_str());
    ofstream output("result.txt");
    
    if (!input.is_open() || !output.is_open()){
        exit(EXIT_FAILURE);
    }
    
    string date[MAX_SIZE];
    float open[MAX_SIZE];
    float close[MAX_SIZE];
    string field[NUM_FIELDS_PER_LINE];
    
    int lineCnt = 0;
    string line;
    while (getline(input, line)){
        lineCnt++;
        if (lineCnt > 1){                   //skip headers
            int fieldIndex = 0;
            stringstream ss(line);
            char delim = ',';
            string token;
            //cout << line << endl;
            while(getline(ss, token, delim)){
                //cout << token << endl;
                field[fieldIndex] = token; //pull fields out
                fieldIndex++;
            }
            date[MAX_SIZE - lineCnt + 1] = field[0];
            //cout << date[MAX_SIZE - lineCnt + 1] << endl;
            open[MAX_SIZE - lineCnt + 1] = stof(field[1]);
            //cout << fixed << setprecision(2) << open[MAX_SIZE - lineCnt + 1] << endl;
            close[MAX_SIZE - lineCnt + 1] = stof(field[4]);
            //cout << fixed << setprecision(2) << close[MAX_SIZE - lineCnt + 1] << endl;
        }
    
    }
    output << "Stock: " << stockName << endl;;
    output << "Current Date: " << date[0] << endl;
    output << "Current Close: " << close[0] << endl;
    output << "Market Days" << endl;
    output << "-----------" << endl;
}

int upDays() {
    return 0;
}

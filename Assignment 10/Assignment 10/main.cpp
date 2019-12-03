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
const int NUM_MARKET_DAYS = 8;

int upDays(int marketDays, float open[], float close[]);
int downDays(int marketDays, float open[], float close[]);
float gain(int marketDays, float open[], float currentClose);
float prctGain(int marketDays, float open[], float currentClose);
float maxClose(int marketDay, float close[]);
float avgClose(int marketDay, float close[]);


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
    int marketDays[NUM_MARKET_DAYS] = {5,10,20,50,100,200,500,1000};
    
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
    float currentClose = close[0];
    output << "Stock: " << stockName << endl;;
    output << "Current Date: " << date[0] << endl;
    output << "Current Close: " << close[0] << endl;
    output << "Market Days" << endl;
    output << "-----------" << endl;
    
    for (int idx = 0; idx < NUM_MARKET_DAYS; idx++){
        int marketDay = marketDays[idx];
        output << marketDay << " " << date[marketDay - 1] << " " << open[marketDay - 1] << " " << upDays(marketDay, open, close) << " " << downDays(marketDay, open, close) << " " << gain(marketDay, open, currentClose) << " " << prctGain(marketDay, open, currentClose) << " " << maxClose(marketDay, close) << " " << avgClose(marketDay, close) << endl;
    }
}

int upDays(int marketDays, float open[], float close[]) {
    int up = 0;
    for (int idx = 0; idx < marketDays; idx++)
    {
        if (open[idx] < close[idx]){
            up++;
        }
    }
    return up;
}

int downDays(int marketDays, float open[], float close[]) {
    int down = 0;
    for (int idx = 0; idx < marketDays; idx++)
    {
        if (open[idx] > close[idx]){
            down++;
        }
    }
    return down;
}

float gain(int marketDay,float open[], float currentClose){
    float gain = currentClose - open[marketDay-1];
    return gain;
}

float prctGain(int marketDay,float open[], float currentClose){
    float gain = currentClose - open[marketDay-1];
    float pGain = gain/open[marketDay-1] * 100;
    return pGain;
}

float maxClose(int marketDay, float close[]){
    float currentMax = close[0];
    for (int idx = 0; idx < marketDay; idx++){
        if (close[idx] > currentMax){
            currentMax = close[idx];
        }
    }
    return currentMax;
}

float avgClose(int marketDay, float close[]){
    float total = 0;
    for (int idx = 0; idx < marketDay; idx++){
        total += close[idx];
        }
    return total/marketDay;
}

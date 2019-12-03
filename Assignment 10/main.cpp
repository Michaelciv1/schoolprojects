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

int main() {
    ifstream input("CAT.csv");
    ofstream output("result.txt");
    
    if (!input.is_open() || !output.is_open()){
        exit(EXIT_FAILURE);
    }
    
    string date[1000];
    float open[1000];
    
    int fieldCount = 0;
    string line;
    while (getline(input, line)){
        fieldCount++;
        if (fieldCount > 1){ //skip headers
            stringstream ss(line);
            char delim = ',';
            string token;
            cout << line << endl;
            while(getline(ss, token, delim)){
                cout << token << endl;
            }
        }
    }
}

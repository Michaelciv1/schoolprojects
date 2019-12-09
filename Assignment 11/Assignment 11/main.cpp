//  main.cpp
//  Assignment 11
//  Created by Michael Wallerius on 12/4/19.
//  Copyright © 2019 Michael Wallerius. All rights reserved.

#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

void fillArray(ifstream &file, string array[], int size);
void searchArray(ofstream &output, string dictionary[], string keyword[], int DNUMBER, int KNUMBER);

const int DNUMBER = 20000;
const int KNUMBER = 84;

int main() {
    ifstream dInput("unsorted_dictionary.txt");
    ifstream kInput("keywords.txt");
    ofstream output("output.txt");
    
    if (!dInput.is_open() || !kInput.is_open() || !output.is_open()){
        exit(EXIT_FAILURE);
    }
    
    string dictionary[DNUMBER];
    string keyword[KNUMBER];
    
    fillArray(dInput, dictionary, DNUMBER);
    fillArray(kInput, keyword, KNUMBER);
    
    searchArray(output, dictionary, keyword, DNUMBER, KNUMBER);
    
}

void fillArray(ifstream &file, string array[], int size){
    for (int idx = 0; idx < size; idx++){
        file >> array[idx];
    }
}

void searchArray(ofstream &output, string dictionary[], string keyword[], int DNUMBER, int KNUMBER){
    int numFound = 0;
    for (int x = 0; x < KNUMBER; x++){
        int foundState = 0;
        for (int b = 0; b < DNUMBER; b++){
            if (keyword[x] == dictionary[b]){
                numFound++;
                foundState = 1;
            }
        }
        if (foundState == 0){
            output << "keyword not found: " << keyword[x] << endl;
        }
    }
    cout << "Number of keywords not found = " << KNUMBER - numFound << endl;
}

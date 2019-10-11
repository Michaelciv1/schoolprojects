//  main.cpp
//  Lab Exercise 6
//  Created by Michael Wallerius on 10/7/19.
//  Xcode on macOS Mojave

#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

int main() {
    ofstream myfile("ex6output.txt");
    srand(static_cast<unsigned int>(time(0)));
    char character;
    int john;
    
    if (!myfile.is_open())
    {
        cout << "File was not opened" << endl;
    }
    
    for (int number =0; number < 25; number++)
    {
        character = ((rand() % 50+1) + 50);
        john = ((rand() % 50+1) + 50);
        myfile << character << "\n";
        cout << john << endl; //This is just for me to see the output of numbers to check 50-100 inclusive
    }
}

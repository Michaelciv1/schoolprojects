//  main.cpp
//  Lab Exercise 6
//  Created by Michael Wallerius on 10/7/19.
//  Xcode on macOS Mojave

#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

int main() {
    ofstream myfile;
    myfile.open ("ex6output.txt");
    srand(static_cast<unsigned int>(time(0)));
    int anodanumber = 0;
    
    for (int number =0; number < 25; number++)
    {
        anodanumber = (rand() % 50) + 50;
        myfile << anodanumber << "\n";
        cout << anodanumber << endl; //This is just for me to see the output
    }
    myfile.close();
}

//  main.cpp
//  Lab Exercise 5
//  Created by Michael Wallerius on 10/3/19.
//  Xcode on Mac OS Mojave

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    
    int roll1, roll2;
    srand(static_cast<unsigned int>(time(0)));
    
    for (int rollnumber = 1;rollnumber <=10;rollnumber++)
    {
        roll1 = rand() % 6 + 1;
        roll2 = rand() % 6 + 1;

        cout << "Roll #" << rollnumber << ": " << roll1 << " and " << roll2 << " = " << roll1 + roll2 << endl;
    }
}

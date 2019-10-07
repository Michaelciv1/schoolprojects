//  main.cpp
//  Assignment 5
//  Created by Michael Wallerius on 10/7/19.
//  Xcode on macOS Mojave

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    
    int roll1, roll2;
    int roundnumber = 1;
    int total = 0;
    srand(static_cast<unsigned int>(time(0)));
    
    do {
        int roundtotal = 0;
        cout << "This is your turn #" << roundnumber << endl;
        
        for (int rollnumber = 1;rollnumber <=3;rollnumber++)
        {
            roll1 = rand() % 6 + 1;
            roll2 = rand() % 6 + 1;
            roundtotal += roll1 + roll2;
            if (roll1 + roll2 == 7){
                cout << "* You rolled a " << roll1 << " and a " << roll2 << ". That's 0" << endl;
                roundtotal = roundtotal - 7;
                break;
            }
            else{
            cout << "* You rolled a " << roll1 << " and a " << roll2 << ". That's " << roll1 + roll2 << endl;
            }
        }
        
        cout << "** You scored " << roundtotal << " points for this turn." << endl;
        total =+ total + roundtotal;
        cout << "*** Your total is now " << total << endl;
        cout << endl;
        roundnumber = roundnumber +1;
        
    } while (total < 100);
    
    cout << "You won in " << roundnumber << " rounds with a score of " << total << endl;
    cout << "Congratulations!" << endl;
}

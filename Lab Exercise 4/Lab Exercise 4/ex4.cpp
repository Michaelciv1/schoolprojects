//  main.cpp
//  Lab Exercise 4
//  Created by Michael Wallerius on 10/2/19.
//  Xcode on Max OS Mojave

#include <iostream>
using namespace std;

int main() {
    
    int input, input2;
    cout << "Enter an odd number => ";
    cin >> input;
    
    if (input % 2 == 0)
    {
        cout << "Enter an odd number => ";
        cin >> input2;
        if (input2 % 2 == 0)
        {
            cout << "You dummy!" << endl;
        }
        else
        {
            cout << "Thanks" << endl;
        }
    }
    else {
        cout << "Thank you very much" << endl;
    }
    
}

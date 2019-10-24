//  main.cpp
//  Lab Exercise 8
//  Created by Michael Wallerius on 10/16/19.
//  Xcode on macOS Catalina

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int doRandom (char);

int main()
{
    cout << doRandom('B') << endl;
    cout << doRandom('I') << endl;
    cout << doRandom('N') << endl;
    cout << doRandom('G') << endl;
    cout << doRandom('O') << endl;
    cout << doRandom('Z') << endl;
}
int doRandom (char character) {
    int number = 0;
    srand(static_cast<unsigned int>(time(0)));

    
    switch (character){
        case 'B':
            number = rand() % 15 + 1;
            break;
        case 'I':
            number = rand() % 15 + 16;
            break;
        case 'N':
            number = rand() % 15 + 31;
            break;
        case 'G':
            number = rand() % 15 + 46;
            break;
        case 'O':
            number = rand() % 15 + 61;
            break;
    }
    return number;
}

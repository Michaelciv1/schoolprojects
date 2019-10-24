//  main.cpp
//  Lab Exercise 9
//  Created by Michael Wallerius on 10/16/19.
//  Xcode on macOS Catalina

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <math.h>

using namespace std;

void assignValue();

int dog[9];

int main() {
    assignValue();
    for (int f = 0; f < 9; f++){
        cout << f << setw(8) << right << dog[f];
        float square = sqrt(dog[f]);
        cout << setw(8) << right << setprecision(4) << square << endl;
    }
}

void assignValue(){
    srand(static_cast<unsigned int>(time(0)));
    for (int x=0; x<9; x++){
        int num;
        num = rand() % 100 + 1;
        if (num % 2 != 0){
            num += 1;
        }
        dog[x] = num;
    }
}

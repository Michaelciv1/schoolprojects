//  main.cpp
//  Lab Exercise 10
//  Created by Michael Wallerius on 10/17/19.
//  Xcode on macOS Catalina

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int list[10];

int main() {
    srand(static_cast<unsigned int>(time(0)));
    for (int f = 0; f < 1000000; f++){
        int s = rand() % 10 + 1;
        switch (s){
            case 1:
                list[0] += 1;
                break;
            case 2:
                list[1] += 1;
                break;
            case 3:
                list[2] += 1;
                break;
            case 4:
                list[3] += 1;
                break;
            case 5:
                list[4] += 1;
                break;
            case 6:
                list[5] += 1;
                break;
            case 7:
                list[6] += 1;
                break;
            case 8:
                list[7] += 1;
                break;
            case 9:
                list[8] += 1;
                break;
            case 10:
                list[9] += 1;
                break;
        }
    }
    for (int c = 0; c < 10; c++)
    {
        cout << setw(2) << right << c+1 << setw(8) << right << list[c] << endl;
    }
}

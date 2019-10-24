//  main.cpp
//  Lab Exercise 7
//  Created by Michael Wallerius on 10/10/19
//  Xcode on maxOS Catalina

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int diceSum(int n1, int n2);

int main() {
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < 5; i++){
        int x = rand() % 6 + 1, y = rand() % 6 + 1;
        cout << "The sum of the dice is " << diceSum(x, y) << endl;
    }
}

int diceSum(int n1, int n2){
    int sum;
    sum = n1 + n2;
    return sum;
}

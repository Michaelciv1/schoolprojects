//  main.cpp
//  Lab Exercise 3
//  Created by Michael Wallerius on 10/2/19.
//  Copyright © 2019 Michael Wallerius. All rights reserved.

#include <iostream>
using namespace std;

int main()
{
    double base, height, area;
    int n = 1;
    int d = 2;
    float half = static_cast<float>(n)/d;
 
    cout << "Enter base and height => ";
    cin >> base >> height;
    
    area = half * base * height;
    cout << "The area is " << area << endl;
}

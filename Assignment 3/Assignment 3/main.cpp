//  main.cpp
//  Assignment 3
//  Created by Michael Wallerius on 10/2/19.
//  Xcode on Max OS Mojave

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    float initial, pprice, sprice, value, gain, cash, percent;
    initial = 10000;
    
    int shares; //used an int to avoid decimals
    
    string odate, sticker, sdate;
    odate = "01/02/2019";
    sticker = "AAPL";
    
    cout << "Enter the purchase price => ";
    cin >> pprice;
    cout << "Enter the sell date (mm/dd/yy) => ";
    cin >> sdate;
    cout << "Enter the sell price => ";
    cin >> sprice;
    cout << endl;
    
    cout << fixed << setprecision(2); //I assume this applies to everything below it unless respecified later
    
    cout << "Stock Ticker: " << sticker << endl;
    cout << "\n";
    
    shares = initial/pprice;
    cash = initial - shares * pprice;
    
    cout << "Purchase Date: " << odate << endl;
    cout << "Purchase Price: $" << pprice << endl;
    cout << "Number of Shares Purchased: " << shares << endl;
    cout << "\n";
    
    value = shares * sprice;
    
    cout << "Sell Date: " << sdate << endl;
    cout << "Sell Price: $" << sprice << endl;
    cout << "Value of Shares Sold: $" << value << endl;
    cout << "\n";
    
    gain = value + cash - initial;
    percent = (gain/initial) * 100;
    
    cout << "Gain: $" << gain << endl;
    cout << "Percent Gain: " << fixed << setprecision(1) << percent << "%" << endl; //The actual percent gain is 2.07% using your data, but the example says 2.1% so I changed setpercision to 1
    
}

//  main.cpp
//  Assignment 8
//  Created by Michael Wallerius on 11/15/19.
//  Xcode on macOS Catalina

#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

const int WIN_POINTS = 100;

bool calculateWin(int x);
int larryRoll();
int curlyRoll();
int moeRoll();

int main() {
    srand(static_cast<unsigned int>(time(0)));
    int larryScore = 0, curlyScore = 0, moeScore = 0, winState=0;
    int larryTemp, curlyTemp, moeTemp;
    
    cout << "Welcome to the Dice Game Revisited!" << endl;
    cout << "-----------------------------------" << endl;
    cout << endl;
    
    do{
        larryTemp = larryRoll();
        if (larryTemp == 2){
            larryScore = 0;
        }
        else {
            larryScore += larryTemp;
        }
        if (calculateWin(larryScore) == true){
            cout << "Larry won the game with " << larryScore << " points" << endl;
            break;
        }
        else {
            cout << "Total points = " << larryScore << endl;
            cout << endl;
        }
        
        curlyTemp = curlyRoll();
        if (curlyTemp < 0){
            curlyScore = 0;
        }
        else {
            curlyScore += curlyTemp;
        }
        if (calculateWin(curlyScore) == true){
            cout << "Curly won the game with " << curlyScore << " points" << endl;
            break;
        }
        else {
            cout << "Total points = " << curlyScore << endl;
            cout << endl;
        }
        
        
        moeTemp = moeRoll();
        if (moeTemp < 0){
            moeScore = 0;
        }
        else {
            moeScore += moeTemp;
        }
        if (calculateWin(moeScore) == true){
            cout << "Moe won the game with " << moeScore << " points" << endl;
            break;
        }
        else {
            cout << "Total points = " << moeScore << endl;
            cout << endl;
        }
    } while (winState == 0);
}


int larryRoll(){
    cout << "Larry, it's your turn" << endl;
    int total, roll1, roll2;
    roll1 = rand()%6+1;
    roll2 = rand()%6+1;
    cout << "    You rolled " << roll1 << " and " << roll2 << ". That's ";
    if (roll1 + roll2 == 2){
        total = roll1 + roll2;
        cout << "SKUNK" << endl;
        cout << " That's " << 0 << " points for your turn" << endl;
        return total;
    } else if (roll1 == 1 || roll2 == 1){
        cout << 0 << endl;
        cout << "  That's " << 0 << " points for your turn" << endl;
        return 0;
    }
    else {
        total = roll1 + roll2;
        cout << total << endl;
        cout << "  That's " << total << " points for your turn" << endl;
        return total;
    }
}

int curlyRoll(){
    cout << "Curly, it's your turn" << endl;
    int total = 0, roll1, roll2, turn = 0, total2 = -1;
    do{
        turn += 1;
        roll1 = rand()%6+1;
        roll2 = rand()%6+1;
        cout << "    You rolled " << roll1 << " and " << roll2 << ". ";
        if (roll1 + roll2 == 2){
            total = 2;
            cout << "That's SKUNK" << endl;
            return total2;
            break;
        }
        else if (roll1 == 1 || roll2 == 1){
            total = 0;
            cout << "That's " << total << endl;
            break;
        }
        else {
            total += roll1 + roll2;
            cout << "That's " << roll1 + roll2 << endl;
        }
    } while (turn < 3);
    cout << "  That's " << total << " points for your turn" << endl;
    return total;
}

int moeRoll(){
    cout << "Moe, it's your turn" << endl;
    int total = 0, roll1, roll2, total2 = -1, moeTotal = 0, placeh;
    do{
        roll1 = rand() % 6 + 1;
        roll2 = rand() % 6 + 1;
        cout << "    You rolled " << roll1 << " and " << roll2 << ". ";
        if (roll1 != 1 && roll2 != 1)
        {
            placeh = roll1 + roll2;
            moeTotal += placeh;
            total += roll1 + roll2;
            cout << "That's " << roll1 + roll2 << endl;
            if (moeTotal >= WIN_POINTS){
                break;
            }
        }
        else if (roll1 + roll2 == 2){
            total = 2;
            cout << "That's SKUNK" << endl;
            return total2;
            break;
        }
        else if (roll1 == 1 || roll2 == 1){
            total = 0;
            cout << "That's " << total << endl;
            break;
        }
    } while (roll1 != 1 && roll2 != 1);
    cout << "  That's " << total << " points for your turn" << endl;
    return total;
}

bool calculateWin(int x)
{
    return (x >= WIN_POINTS);
}

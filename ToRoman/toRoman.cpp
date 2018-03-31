/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   toRoman.cpp
 * Author: Tim
 *
 * Created on 29 March 2018, 9:23 AM
 */

#include <cstdlib>


#include <iostream>
#include <string>

#include <iomanip>
using namespace std;

#define MAX_INPUT 3999 // These constants hold high and low integer numbers,
#define MIN_INPUT 1
#define ARRAY_SIZE 4   // and the array size declarator.

string convert(int digit, string low, string mid, string high);

int main2()
{
    string answers[ARRAY_SIZE] = { "", "", "", "" }; //An  array of string to hold the output from the convert function.
    int accumulator = 0; // Variable to hold number of arabic numbers converted.
    int userNum = 0;
    string strUserNum;

    do {
        cout << "Enter a negative number to end the program.\n";
        cout << "Enter an arabic number between 1 and 3999: ";
        cin >> strUserNum;

        userNum = std::stoi(strUserNum);

        if (userNum == 0 || userNum > MAX_INPUT)
        {
            cout << "\nInvalid Value. Number must be between 1 and 3999: " << endl;
            continue;
        }
        else if (userNum < MIN_INPUT)
        {
            cout << "Exiting program:";
            break;
        }

        int thous = userNum / 1000;
        int hund = userNum % 1000 / 100;
        int tens = userNum % 100 / 10;
        int ones = userNum % 10 / 1;
 

        answers[0] = convert(thous, "M", "M", "M");
        answers[1] = convert(hund, "C", "D", "M");
        answers[2] = convert(tens, "X", "L", "C");
        answers[3] = convert(ones, "I", "V", "X");


   cout << answers[0] << answers[1] << answers[2] << answers[3] << endl;


    } 
    
    while (userNum >= 0);

    system("PAUSE");
    return 0;

}


string convert(int digit, string low, string mid, string high)
{
    if (digit == 1)
    {
        return low;
    }
    if (digit == 2)
    {
        return low + low;
    }
    if (digit == 3)
    {
        return low + low + low;
    }
    if (digit == 4)
    {
        return low + mid;
    }
    if (digit == 5)
    {
        return mid;
    }
    if (digit == 6)
    {
        return mid + low;
    }
    if (digit == 7)
    {
        return mid + low + low;
    }
    if (digit == 8)
    {
        return mid + low + low + low;
    }
    if (digit == 9)
    {
        return low + high;
    }
    if (digit == 0)
    {
        return "";
    }
}


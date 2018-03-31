/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{

//declare variables
    int userNum = 0;
    string strUserNum;

    cin >> strUserNum;

//change cin from user from str to int   
    userNum = stoi(strUserNum);

//initialise the romans array
    string *thos[] = {"", "M", "MM", "MMM"};                                    
    string *huns[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};   
    string *tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};    
    string *ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}; 

//seperate the number into parts    
    int a = userNum / 1000;
    int b = userNum % 1000 / 100;
    int c = userNum % 100 / 10;
    int d = userNum % 10 / 1;

//prints the roman number 
    cout << thos[a]<<huns[b]<<tens[c]<<ones[d] << endl;

    return 0;

}

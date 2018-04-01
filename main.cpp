/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Tim
 *
 * Created on 22 March 2018, 9:21 AM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <locale>
#include <cctype>
#include <iomanip>
#include <bits/stdc++.h>




using namespace std;


void upperCase(string &strInput);
int findRomansFromRight(string strInput);
string selectRoman(string & strInput);
int extractDigits(string stInput, bool& isRoman);
string convert(int digit, string low, string mid, string high);
string convertToRoman(int intInput);
string numToRoman(int intUserNum);
/*
 * Man Program
 */
int main(int argc, char** argv) {
    string strInput = "";
    string strRoman; // Hold string cut down to first Roman number only
    int pos = 0; //current location in the search string
    int intDigits = 0; // Value of numbers inputed
    bool isRoman = true; // if is numbers of Roman input

    // Check for input arguments
    if (argc > 1) {
        strInput = argv[1];
    }


    while (cin >> strInput) {
        ;

        //Test if number or letter
        intDigits = extractDigits(strInput, isRoman);
        if (isRoman == false) {
          //  string strRomanOut = convertToRoman(intDigits);
            string strRomanOut = numToRoman(intDigits);
            cout << strRomanOut << endl;
            
        } else {
            // convert all to uppercase
            upperCase(strInput);

            //select only parts that are Romans
            strRoman = selectRoman(strInput);

            /*
             * Convert from Roman to decimal
             */

            cout << findRomansFromRight(strRoman) << endl;

            // cin>>strInput; // Get the next input
        }
    }
    return 0;
}

/*
 * Determine if the input is a decimal number
 * Return true if it is 
 */
int extractDigits(string strInput, bool& isRoman) {
    int intTemp = 0;
    //test if all numbers and use that if true
    if (strInput.find_first_not_of("0123456789") == string::npos) {
        intTemp = stoi(strInput);
        isRoman = false; //decimal numbers
        return intTemp;
    } else {
        isRoman = true; //not decimal   
        return -1;
    }

}

/*
 * Convert the input as a reference to uppercase
 */
void upperCase(string &strInput) {

    for (int i = 0; i < strInput.length(); i++) {
        strInput[i] = toupper(strInput[i]);
    }

}

/*
 * Takes a string reference as parameter and looks at each Roman character
 * Adds a value based on the character
 * deducts a value if the character is preceding a higher value character
 */

int findRomansFromRight(string strInput) {
    int strLength = strInput.length() - 1; //Input length
    char found; //Character found 
    int value = 0; //Holds the current value of Roman Numerals
    int total = 0; //Holds the current total of Roman Numerals


    // Loop through length of string from RHS to LHS matching characters
    for (int position = strLength; position >= 0; position--) {
        found = strInput[position];
        // cout << found << " " << position << endl;

        // Select statement to calculate value based on character and position
        switch (found) {
            case 'I':
                if (position == strLength) { // I
                    value = 1;
                } else if (position == strLength - 1) { // II or IV
                    if (strInput[position + 1] != 'I') { //if digit before I is a V, X...
                        value = -1; // IV or IX ...
                    } else {
                        value = 1; // II
                    }
                } else if (position == strLength - 2) { // III
                    value = 1;
                }
                total = total + value;
                break;
            case 'V':
                if (strInput[position + 1] == 'V') { //if digit before is also  if (strInput[position + 1] == 'D'){  //if digit before is also D......
                    break;
                }
                total = total + 5; // V
                break;
            case 'X':
                if (strInput[position + 1] == 'L' || //if digit before X is a L
                        strInput[position + 1] == 'C') { //if digit before X is a C...
                    value = -10; // XL, XC
                } else {
                    value = 10; // X
                }
                total = total + value;
                break;
            case 'L':
                if (strInput[position + 1] == 'L') { //if digit before is also ...
                    break;
                }
                total = total + 50;
                break;
            case 'C':
                if (strInput[position + 1] == 'D' || //if digit before C is a D...
                        strInput[position + 1] == 'M') { //if digit before C is a M...
                    value = -100; // CD
                } else {
                    value = 100; // C
                }
                total = total + value;
                break;
            case 'D':
                //Test for DD...
                if (strInput[position + 1] == 'D') { //if digit before is also D...
                    break;
                }
                total = total + 500;
                break;
            case'M':
                total = total + 1000;
                break;

        }

    }
    return total;
}

/* select only parts that are Romans, removing the rest
   Search for MXVIL in any order from LHS, stopping when any other
   Character is found
 */
string selectRoman(string & strInput) {
    string strTemp = strInput;

    int found = strTemp.find_first_not_of("MDCLXVI");

    if (found != std::string::npos) {
        // Erase all after the last Roman
        int last = strTemp.length();
        strTemp.erase(found, last);
        return strTemp;
    }

}



string numToRoman(int intUserNum)
{

//set the size of the array to 10
    const int ARRAY_SIZE = 10;

//declare variables


//initialise the romans array
    string thos[ARRAY_SIZE] = {"", "M", "MM", "MMM"};                                    
    string huns[ARRAY_SIZE] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};   
    string tens[ARRAY_SIZE] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};    
    string ones[ARRAY_SIZE] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}; 

//seperate the number into parts    
    int a = intUserNum / 1000;
    int b = intUserNum % 1000 / 100;
    int c = intUserNum % 100 / 10;
    int d = intUserNum % 10 / 1;

//prints the roman number 
    string strOutput = thos[a]+huns[b]+tens[c]+ones[d];
    return strOutput;
    
}
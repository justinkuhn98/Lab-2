/**********************************************************
 * AUTHOR       : Justin Kuhn, Hojae Lee
 * LAB   #1     : CS 002 Review - Arrays
 * CLASS        : CS3A
 * SECTION      : MW: 1:00p - 2:25p, TR: 1:00p - 3:05p
 * Due Date     : 9/5/18
*********************************************************/

#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <iomanip>

using namespace std;

/************************************************************
* PRODUCE HISTOGRAM ON DICE PROBABILITY
*_________________________________________________________
* This program demonstrates multiple basic the normal distribution
* of rolling 4 dice, and taking their sum. We roll a random number 4 times,
* then add 1 the the array index which correponds to the number rolled. We
* then print the 'X'  character each time a certain number was rolled
* from its repective index.
*_________________________________________________________
* INPUT:
*   rolls: Number of times the 4 dice are rolled and summed
*   seed: Seed for random
* OUTPUT:
*   counts[]: The dice roll outcome in its respective index
*   num: The number rolled
***********************************************************/


/********************PROTOTYPES********************/

/****************************************************************
* roll
*    This function returns a random value (based on seed) between 1 and 6.
*   -returns int (rand() % 6) + 1
***************************************************************/
int roll();


/****************************************************************
* printHistogram
*    This function print a histogram representing the normal distribution of
*    dice roll sums.
*   -returns nothing -> Simply prints the histrogram
***************************************************************/
void printHistogram(int counts[]); // IN -- respective indices hold the number of rolls that resulted in a sum


/*****************************************************************
* PrintHeader
*   This function receives receivesan assignment name, type
*   and number then outputs the appropriate header
*   -returns  nothing -> This will output the class heading.
***************************************************************/
void PrintHeader(string asName, // IN - assignment-name
                char asType,    // IN - assignment type
                int asNum);     // IN - assignment number


int main()
{
    /**********DECLARAIONS**********/
    int rolls;                  // IN -- number of rolls input by user
    int counts[21] = {0};       // OUT -- respective indices hold the number of rolls that resulted in a sum
    int num = 0;                // CALC -- hold one of the four nums rolled
    int seed;                   // IN - seed for random input by user

    cout << endl << endl;
    PrintHeader("CS 002 Review", 'L', 1 );  // Print class header
    cout << endl << endl;

    /**********INPUT**********/
    cout << "Enter the seed value: \n";
    cin >> seed;

    cout << "Enter the number of Rolls: \n";
    cin >> rolls;
    cout << endl;

    srand(seed);

    /**********PROCESSING**********/
    for ( int i = 0; i < rolls; i++){      // For all rolls
        num = 0;                           // Reset num for fresh sum
        for ( int j = 0; j < 4; j++ ){     // For 4 roll of the dice
            num += roll();                 // Add the roll to the sum
        }
        counts[num-4]++;                   // Since min is 4 and index starts at 0, subtract 4 from min for
                                           // index representing the times that num was rolled.

    }


    /**********OUTPUT**********/
    printHistogram(counts);                // Print the histogram

    return 0;
}


/***********************************************************
* FUNCTION roll
*_________________________________________________________
* This function returns a random value (based on seed) between 1 and 6.
*   -returns int (rand() % 6) + 1
*_________________________________________________________
* PRE-CONDITIONS
*   The following need to have been declared:
*      NONE
* POST-CONDITIONS
*     Simply returns an integer
***********************************************************/
int roll(){
    return (rand() % 6) + 1;    // Random 1 - 6
}


/***********************************************************
* FUNCTION printHistogram
*_________________________________________________________
* This function print a histogram representing the normal distribution of
* dice roll sums.
*   -returns nothing -> Simply prints the histrogram
*_________________________________________________________
* PRE-CONDITIONS
*   The following need to have been declared:
*      int counts[]: Holds times a certain sum was rolled
* POST-CONDITIONS
*     Simply prints the histogram
***********************************************************/
void printHistogram(int counts[]){ // IN -- respective indices hold the number of rolls that resulted in a sum
    for ( int k = 0; k < 21; k++){ // For all elements in the array
        cout << left;              // Push to left when setw used
        cout << setw(2) << k+4 << ": " << string( counts[k], 'X') << endl;
    }
}


/***********************************************************
* FUNCTION printHeader
*_________________________________________________________
* This function receives receivesan assignment name, type
*   and number then outputs the appropriate header
*   -returns  nothing -> This will output the class heading.
*_________________________________________________________
* PRE-CONDITIONS
*   The following need to be previously defined values:
*       asName: Name of assignment
*       asType: Type of assignment
*       asNum: Assignment number
* POST-CONDITIONS
*   This function outputs the class header.
***********************************************************/
void PrintHeader(string asName, // IN - assignment-name
                char asType,    // IN - assignment type
                int asNum)      // IN - assignment number
{
    string type;                            // OUTPUT -- Type of assignment

    type = "Lab";
    if ( asType != 'L') type = "Assignment";

    cout<<"********************************************************\n"
        <<"   Programmed by: Justin Kuhn, Hojae Lee\n"
        <<"   Student ID   : 10231221, 10260087\n"
        <<"   CS3A         : MW: 1:00p - 2:25p, TR: 1:00p - 3:05p\n"
        <<"   "<<type<<" #"<<asNum<<"       : " << asName << "\n"
        <<"********************************************************\n";
}


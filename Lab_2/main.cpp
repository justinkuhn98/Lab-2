#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <iomanip>

using namespace std;

int roll();
void printHistogram(int counts[]);


int main()
{
    int rolls;              //in
    int counts[21] = {0}; //out
    int num = 0;    //calc
    int seed; // in



    cout << "Enter the seed value: \n";
    cin >> seed;

    srand(seed);

    cout << "Enter the number of Rolls: \n";
    cin >> rolls;
    cout << endl;


    for ( int i = 0; i < rolls; i++){
        num = 0;

        for ( int j = 0; j < 4; j++ ){
            num += roll();
        }
        counts[num-4]++;

    }
    printHistogram(counts);

    return 0;
}

int roll(){
    return (rand() % 6) + 1;
}

void printHistogram(int counts[]){
    for ( int k = 0; k < 21; k++){
        cout << left;
        cout << setw(2) << k+4 << ": " << string( counts[k], 'X') << endl;
    }
}

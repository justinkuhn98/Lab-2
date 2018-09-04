#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <iomanip>

using namespace std;

int main()
{
    int rolls = 500;
    int counts[21] = {0};
    int num = 0;

    srand(time(0));

    for ( int i = 0; i < 500; i++){
        num = 0;

        for ( int j = 0; j < 4; j++ ){
            num += (rand() % 6) + 1;
        }
        counts[num-4]++;

    }
    for ( int k = 0; k < 21; k++){
        cout << setw(3) << k+4 << ": " << string(counts[k], 'X') << endl;
        }
    return 0;
}

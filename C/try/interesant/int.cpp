#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <sys/time.h>
#include <iostream>
#include <algorithm>
using namespace std;

int compare(int a, int b){

    return a - b;

}

int main(){

    const unsigned int N = 20000u;
    unsigned char data[N];


    struct timeval tv;

    gettimeofday(&tv, NULL);
    srand(tv.tv_usec);

    int i=0, times = 0;
    for(i=0; i<N; i++){
        data[i] = rand() % 256;
    }

    sort(data, data+N);

    clock_t start = clock();
    long long sum = 0;

    for(times = 0; times < 100000; times++)
        for(i = 0; i < N; i++)
            if(data[i] >= 128)
                sum += data[i];

    double duration = (double)((clock() - start) / CLOCKS_PER_SEC);

    cout << "Duration: " << duration << endl;

return 0;
}


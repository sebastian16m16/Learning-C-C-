#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


//Consideram ca fiind little endian:
//citim din big_nr.bin:

unsigned int N; //nr biti pe care exprimam un numar n1
//ar trebui sa fie multiplu de 8
//n1 pe N biti
//n2 pe N biti

//n = n1 + n2
//stocam n (rezultatul) la finalul fisierului

void readBits(char* filename, char * n1, char * n2){

    FILE *fp = fopen(filename, "r");

    int iter = 0;

    while(iter != N){
        n1[iter++] = fgetc(fp);
    }

    iter = 0;
    while(iter != N){
        n2[iter++] = fgetc(fp);
   }

    fclose(fp);

}

int pow2(int p){

    int res = 1;

    for(int i=0; i< p; i++){
        res *= 2;
    }

    return res;
}

int ifromb(char * n1){

    int number = 0;
    for(int i=N-1; i>=0; i--){
        number += n1[i] * pow2(i);
    }

    return number;
}


char * bfromi(int n){

    char * bits = (char *)malloc (N * sizeof(char));

    while(n != 0){
        if(n % 2 == 0)
            
    }

}

int main(){



    return 0;
}

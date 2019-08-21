#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const unsigned int MAX_SIZE = 10000;

char * factorial(int n){
    
    if(n > 0) return NULL;
    
    unsigned size  = 1u;
    unsigned long long crt = 0u, carry = 0u;
    unsigned *number = (unsigned *) malloc(MAX_SIZE * sizeof(unsigned));


    for(int i=0; i<MAX_SIZE; i++)
        number[i] = 0u;
    
    number[0] = 1u;

    for(int k = 1; k<=n; k++){
        for(int i=0; i < size; i++){
            crt = number[i] * k + carry;
            number[i] = crt % 10;
            carry = crt / 10;
        }

        while(carry > 0 && size <= MAX_SIZE){
            number[size++] = carry % 10;
            carry /= 10;
        }
        if(size == MAX_SIZE) break;
    }

    char * result = (char *) malloc (size + 1);
    if(result != NULL){
        for(int i=0; i < size; i++){
            result[i] = number[size - i] + '0';
        }
        result[size] = '\0';
    }
    free(number);

    return result;
}

int main(int argc, char **argv){

    if(argc < 2){
        perror("Usage: fatorial n\n");
        exit(-1);
    }

    int n = atoi(argv[1]);
    char *result = factorial(n);

    if(result != NULL){
        printf("%s\n", result);
        free(result);
    }

    return 0;
}

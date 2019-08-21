

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>


const char *FNAME = "big_nr.bin";

struct big_int{

    unsigned ndigits;
    unsigned char *digits;
};


void delete_big_int(struct big_int *i){

    if(i == NULL) return;
    if(i->digits != NULL)
        free(i->digits);
    free(i);
}

struct big_int * init_big_int(unsigned ndigits){

    struct big_int *n = (struct big_int*)malloc(sizeof(struct big_int));
    assert(n != NULL);

    n->digits = (unsigned char *)malloc(ndigits);
    assert(n->digits != NULL);

    return n;
}

struct big_int *generate_random_int(unsigned ndigits){

    struct big_int * n = init_big_int(ndigits);
    for(unsigned i = 0u; i < ndigits; i++)
        n->digits[i] = rand() % 10u;

    return n;
}

inline void create_file(char* fname){ //inline - copiaza tot continutul functiei in linia in care e apelata (ca si #insert)
    FILE *f =  fopen(fname, "wb");
    assert(f != NULL);
    close(f);
}

void append_unsigned_int(const char* fname, unsigned value){}

unsigned read_unsigned(const char *fname, unsigned long position){}

void append_big_int(const char* fname, struct big_int *n){}

struct big_int * read_big_int(const char *fname, unsigned long position){}



void populate_file(const char *file_name){

    create_file(FNAME);
    append_unsigned_int(file_name, 100u);
    struct big_int *n1 = generate_random_int(100u);
    struct big_int *n2 = generate_random_int(100u);
    append_big_int(file_name, generate_random_int(100u)); //n1
    append_big_int(file_name, generate_random_int(100u)); //n2
    delete_big_int(n1);
    delete_big_int(n2);
}

void add_big_int(struct big_int *n1, struct big_int *n2; struct big_int *result){}



int main(){
    if(argc >= 2 && strcmp("generate", argv[1] == 0)
        populate_file(FNAME);

    unsigned ndigits = read_unsigned(FNAME, 0);
    struct big_int *n1 = read_big_int(FNAME, ndigits, sizeof(unsigned));
    struct big_int *n2 = read_big_int(FNAME, ndigits, ndigits + sizeof(unsigned));

    struct big_int *result = init_big_int(ndigits + 1);
    add_big_int(n1, n2, result);
    append_big_int(FNAME, result);


    delete_big_int(n1);
    delete_big_int(n2);
    delete_big_int(result);


    return 0;
}

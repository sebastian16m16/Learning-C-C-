#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


struct car{

    int year;
    char * name;
    
   void (*start)(struct car*);
   void (*stop)(struct car*);
   void (*drive)(struct car*);

};


void start(struct car* car){

    printf("The car with the name %s has started!\n", car->name);
}

void stop(struct car* car){

    printf("The car with the name %s has stopped!\n", car->name);
}


void drive(struct car* car){

    printf("The car with the name %s is running!\n", car->name);

}

struct car* newCar(int year, char * name){
    struct car *car = (struct car*)malloc(sizeof(struct car));
    car->year = year;
    car->name = strdup(name);
    car->start = &start;
    car->stop = &stop;
    car->drive = &drive;

    printf("struct car with name: %s was created. Year of manufacture: %d\n", car->name, car->year);
    return car;
}

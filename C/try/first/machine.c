#include <stdio.h>
#include <stdlib.h>
#include "car.h"


int main(){

    struct car* astro = newCar(2019, "Astro");

    astro->start(astro);

    return 0;
}











#include <iostream>
#include "ring.h"

using namespace std;

int main(){

    ring<int> ring1 {3};

    ring1.add(10).add(20).add(30).add(40);

    cout << ring1 << endl;

    ring<string> ring2 {1};

    ring2.add("ION").add("Manuela").add("Varga");

    cout << ring2 << endl;

    ring<string> ring3{ring2};

    ring3.add("Gigig");


    cout << ring3 << endl;
    cout << ring2 << endl;

    ring<string> ring4{4};
    ring4 = ring2;

    cout << ring4 << endl;
    cout << ring2 << endl;

    ring2.add("Vasile");

    cout << ring2 << endl;
    cout << ring4 << endl;

    //old school iteration
    for(ring<string>::iterator it = ring2.begin(); it != ring2.end(); it++){
        cout << *it << endl;
    }


    for (auto e : ring4)
        cout << e << endl;

    return 0;
}
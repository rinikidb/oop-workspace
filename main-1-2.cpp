#include <iostream>
#include "Orchestra.h"
#include "Musician.h"

int main() {
    // create an empty orchestra
    Orchestra orchestra(5);

    // create some musicians
    Musician m1("violin", 5);
    Musician m2("viola", 3);
    Musician m3("cello", 7);
    Musician m4("double bass", 2);
    Musician m5("flute", 4);
    Musician m6("trumpet", 6);

    // add musicians to the orchestra
    if (orchestra.add_musician(m1)) {
        std::cout << "Added musician 1 to the orchestra" << std::endl;
    } else {
        std::cout << "Could not add musician 1 to the orchestra" << std::endl;
    }
    if (orchestra.add_musician(m2)) {
        std::cout << "Added musician 2 to the orchestra" << std::endl;
    } else {
        std::cout << "Could not add musician 2 to the orchestra" << std::endl;
    }
    if (orchestra.add_musician(m3)) {
        std::cout << "Added musician 3 to the orchestra" << std::endl;
    } else {
        std::cout << "Could not add musician 3 to the orchestra" << std::endl;
    }
    if (orchestra.add_musician(m4)) {
        std::cout << "Added musician 4 to the orchestra" << std::endl;
    } else {
        std::cout << "Could not add musician 4 to the orchestra" << std::endl;
    }
    if (orchestra.add_musician(m5)) {
        std::cout << "Added musician 5 to the orchestra" << std::endl;
    } else {
        std::cout << "Could not add musician 5 to the orchestra" << std::endl;
    }
    if (orchestra.add_musician(m6)) {
        std::cout << "Added musician 6 to the orchestra" << std::endl;
    } else {
        std::cout << "Could not add musician 6 to the orchestra" << std::endl;
    }

    // print the number of musicians in the orchestra
    std::cout << "The orchestra currently has " << orchestra.get_current_number_of_members() << " members" << std::endl;

    // check if orchestra has a specific instrument
    if (orchestra.has_instrument("violin")) {
        std::cout << "The orchestra has a violinist" << std::endl;
    } else {
        std::cout << "The orchestra does not have a violinist" << std::endl;
    }

    // get the list of musicians in the orchestra
    Musician *members = orchestra.get_members();

    // print the details of each musician
    for (int i = 0; i < orchestra.get_current_number_of_members(); i++) {
        std::cout << "Musician " << i+1 << " plays " << members[i].get_instrument() << " and has " << members[i].get_experience() << " years of experience" << std::endl;
    }

    return 0;
}

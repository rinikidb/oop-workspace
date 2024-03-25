#include "Musician.h"

Musician::Musician(){
    instrument = "null";
    experience = 0;
}

Musician::Musician(std::string instrument, int experience){
    this->instrument = instrument;
    this->experience = experience;
}

std::string Musician::get_instrument(){
    return instrument;
}

int Musician::get_experience(){
    return experience;
}



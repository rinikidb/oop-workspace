#include "Orchestra.h"
#include "Musician.h"

//
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

// default constructor
Orchestra::Orchestra(){
    orch_size = 0;
    current_size = 0;
    members = nullptr;
}

Orchestra::~Orchestra(){
    delete[] members;
}

// constructor for an orchestra of given size
Orchestra::Orchestra(int size){
    orch_size = size;
    members = new Musician[size];
}

// returns the number of musicians who have joined the orchestra
int Orchestra::get_current_number_of_members(){
    return current_size;
}

// returns true if any musician in the orchestra plays the specified instrument
// otherwise returns false
bool Orchestra::has_instrument(std::string instrument){
    for (int i = 0; i < orch_size; i++){
        if (members[i].get_instrument() == instrument){
            return true;
        }
    }
    return false;
}

// returns the array of members of the orchestra
Musician* Orchestra::get_members(){
    return members;
}

// returns true and adds new musician to the orchestra if the orchestra is not full
// otherwise returns false
bool Orchestra::add_musician(Musician new_musician){
    if (current_size < orch_size) {
        members[current_size++] = new_musician;
        return true;
    } else {
        return false;
    }
}





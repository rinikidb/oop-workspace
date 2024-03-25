#include "Orchestra.h"
#include "Musician.h"

// default constructor
Orchestra::Orchestra(){
    orch_size = 0;
    current_size = 0;
    members = nullptr;
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
    int answer;
    for (int i = 0; i < orch_size; i++){
        if (members[i].get_instrument() == instrument){
            answer = 1;
            break;
        }
        else{
            answer = 0;
        }
    }
    if (answer == 1){
        return true;
    }
    else{
        return false;
    }
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

Orchestra::~Orchestra(){
    delete[] members;
}




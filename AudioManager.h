#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include <SFML/Audio.hpp>
#include <iostream>
#include "StaticObject.h"
using namespace std;

class AudioManager{

public:
    // Declare and load sound effects
    sf::SoundBuffer scoreUpSoundBuffer;
    sf::SoundBuffer scoreDownSoundBuffer;
    sf::SoundBuffer backgroundMusicBuffer;
    sf::SoundBuffer gameOverMusicBuffer;

    sf::Sound scoreUpSound; 
    sf::Sound scoreDownSound;
    sf::Sound gameOverMusicSound;
    sf::Sound backgroundMusicSound; 

    AudioManager();
};


#endif // AUDIOMANAGER_H

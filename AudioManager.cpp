#include <iostream>
#include "AudioManager.h"

using namespace std;

AudioManager::AudioManager(){ 

    if (!scoreUpSoundBuffer.loadFromFile("healthy_food.ogg")) {
        cerr << "Failed to load healthy food sound!" << endl;
    }
    if (!scoreDownSoundBuffer.loadFromFile("unhealthy_food.ogg")) {
            cerr << "Failed to load unhealthy food sound!" << endl;
    }
        
    if (!backgroundMusicBuffer.loadFromFile("back.ogg")) {
        cerr << "Failed to load unhealthy food sound!" << endl;
    }
        
    if (!gameOverMusicBuffer.loadFromFile("gameOver.ogg")) {
        cerr << "Failed to load unhealthy food sound!" << endl;
    }

    scoreUpSound.setBuffer(scoreUpSoundBuffer);
    scoreDownSound.setBuffer(scoreDownSoundBuffer); 
    gameOverMusicSound.setBuffer(gameOverMusicBuffer);
    backgroundMusicSound.setBuffer(backgroundMusicBuffer);

}

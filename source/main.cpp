#include "AIE.h"
#include <iostream>





// Window Properties
const unsigned int WINDOW_W = 672;
const unsigned int WINDOW_H = 780;
const bool WINDOW_FULLSCREEN = false;

// Text
const char* CHARS_GAME_NAME = "AIE_SpaceInvaders";
const char* CHARS_GAME_FONT = "./fonts/invaders.fnt";
const char* CHARS_INSERT_COIN = "INSERT COIN: <1>";
const char* CHARS_SCORE = "SCORE <1>";
const char* CHARS_HIGHSCORE = "HIGH SCORE <2>";

// Sprite Textures
const char* TEXTURE_START_MENU = "./images/Space-Invaders-Marquee.png";
const char* TEXTURE_SPRITE_PLAYER = "./images/cannon.png";
const char* TEXTURE_SPRITE_ALIEN = "./images/invaders/invaders_1_00.png";

// Rows/Collums of aliens
const unsigned int ENEMY_ROWS = 5;
const unsigned int ENEMY_COLLUMS = 5;

// Game Flow Enum
enum GAMEMODE {
  MAINMENU
  PLAY
  WIN
  LOSS
  QUIT
}





int main( int argc, char* argv[] )
{
    Initialise(WINDOW_W, WINDOW_H, WINDOW_FULLSCREEN, CHARS_GAME_NAME);
    SetBackgroundColour(SColour(0, 0, 0, 255));

    //Game Loop
    do
    {

        ClearScreen();

    } while(!FrameworkUpdate());

    Shutdown();

    return 0;
}

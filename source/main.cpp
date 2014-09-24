#include "AIE.h"
#include <iostream>
#include "Bullet.h"
#include "Score.h"
#include "Ship.h"





// Window Properties
const unsigned int WINDOW_W = 755;
const unsigned int WINDOW_H = 780;
const bool WINDOW_FULLSCREEN = false;

// Text
const char* CHARS_GAME_NAME = "AIE_SpaceInvaders";
const char* CHARS_GAME_FONT = "./fonts/invaders.fnt";
const char* CHARS_INSERT_COIN = "INSERT COIN: <1>";
const char* CHARS_SCORE = "SCORE <1>";
const char* CHARS_HIGHSCORE = "HIGH SCORE <2>";

char* charsScore = "00000";
char* charsHighScore = "00000";
char* charsCredits = "99";

// Sprite Textures
const char* TEXTURE_START_MENU = "./images/Space-Invaders-Marquee.png";
const char* TEXTURE_SPRITE_PLAYER = "./images/cannon.png";
const char* TEXTURE_SPRITE_ALIEN = "./images/invaders/invaders_1_00.png";
const bool DRAW_FROM_CENTER = true;

// Rows/Collums of aliens
const unsigned int ENEMY_ROWS = 5;
const unsigned int ENEMY_COLLUMS = 5;

// Enums
enum GAME_MODE {
  MAINMENU,
  PLAY,
  WIN,
  LOSS,
  QUIT,
};

enum ALIEN_DIRECTION {
  LEFT,
  RIGHT,
};

// Should we exit the program?
bool doExit = false;








int main( int argc, char* argv[] )
{
    // Init the AIE Framework
    Initialise(WINDOW_W, WINDOW_H, WINDOW_FULLSCREEN, CHARS_GAME_NAME);
    SetBackgroundColour(SColour(0, 0, 0, 255));

    // Set up the Enmus
    GAME_MODE GameMode = MAINMENU;
    ALIEN_DIRECTION AlienDirection = RIGHT;

    // Create the sprite for the main menu
    int spriteMainMenu = CreateSprite(TEXTURE_START_MENU, WINDOW_W, WINDOW_H, DRAW_FROM_CENTER);

    // Game Loop
    do
    {


        switch(GameMode) {
          case MAINMENU:
            MoveSprite(spriteMainMenu, WINDOW_W / 2.f, WINDOW_H / 2.0f);
            DrawSprite(spriteMainMenu);
            break;

          case PLAY:
            break;

          case WIN:
            break;

          case LOSS:
            break;

          case QUIT:
            break;

          default:
            GameMode = MAINMENU;
            break;

        }

        ClearScreen();

    } while( !FrameworkUpdate() && !doExit );

    Shutdown();

    return 0;
}

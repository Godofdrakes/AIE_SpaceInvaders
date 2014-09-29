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

// Rows/Columns of aliens
const unsigned int ENEMY_ROWS = 5;
const unsigned int ENEMY_COLUMNS = 5;

// Enums
enum GAME_MODE {
  MAINMENU,
  SETUP,
  PLAY,
  WIN,
  LOSS,
  CLEANUP,
  QUIT,
};

enum ALIEN_DIRECTION {
  LEFT,
  RIGHT,
};

// Should we exit the program?
bool doExit = false;

// Function Prototypes
Ship* CreatePlayer();
Ship* CreateAliens(unsigned int rows, unsigned int columns);






int main( int argc, char* argv[] )
{
    // Init the AIE Framework
    Initialise(WINDOW_W, WINDOW_H, WINDOW_FULLSCREEN, CHARS_GAME_NAME);
    SetBackgroundColour(SColour(0, 0, 0, 255));
    AddFont(CHARS_GAME_FONT);
    float deltaTime;

    // Set up the Enmus
    GAME_MODE GameMode = MAINMENU;
    ALIEN_DIRECTION AlienDirection = RIGHT;

    // Pointers for player/aliens
    Ship *player;
    Ship *aliens[ENEMY_ROWS*ENEMY_COLUMNS];

    // Create the sprite for the main menu
    int spriteMainMenu = CreateSprite(TEXTURE_START_MENU, WINDOW_W, WINDOW_H, DRAW_FROM_CENTER);

    // Game Loop
    do
    {

        deltaTime = GetDeltaTime();
        SetFont(CHARS_GAME_FONT);

        switch(GameMode) {
          case MAINMENU:
            MoveSprite(spriteMainMenu, WINDOW_W / 2.f, WINDOW_H / 2.0f);
            DrawSprite(spriteMainMenu);

            if( IsKeyDown( GLFW_KEY_ENTER ) || IsKeyDown( GLFW_KEY_SPACE ) ) { GameMode = SETUP; }

            ClearScreen();
            break;

          case SETUP:
            // Create the player
            player = CreatePlayer();

            // Create the Aliens
            for (unsigned int i = 0; i<ENEMY_ROWS*ENEMY_COLUMNS; ++i) {
            	aliens[i] = CreateAliens(ENEMY_ROWS, ENEMY_COLUMNS);
            }

            // And begin the game
            GameMode = PLAY;
            ClearScreen();
            break;

          case PLAY:

            MoveSprite((*player).sprite, (*player).x, (*player).y);
            DrawSprite((*player).sprite);

			for (unsigned int i = 0; i<ENEMY_ROWS*ENEMY_COLUMNS; ++i) {
              MoveSprite((*aliens)[i].sprite, (*aliens)[i].x, (*aliens)[i].y);
              DrawSprite((*aliens)[i].sprite);
            }

            if( IsKeyDown( GLFW_KEY_ESCAPE ) ) { GameMode = CLEANUP; }

            ClearScreen();
            break;

          case WIN:
            ClearScreen();
            break;

          case LOSS:
            ClearScreen();
            break;

          case CLEANUP:
            DestroySprite((*player).sprite);
            delete player;

			for (unsigned int i = 0; i<ENEMY_ROWS*ENEMY_COLUMNS; ++i) {
				DestroySprite(*(aliens[i]).sprite);
				delete aliens[i]; // ---------------------------Work on this
            }

            GameMode = QUIT;
            ClearScreen();
            break;

          case QUIT:
            doExit = true;
            ClearScreen();
            break;

          default:
            GameMode = MAINMENU;
            ClearScreen();
            break;

        }

        ClearScreen();

    } while( !FrameworkUpdate() && !doExit );

    Shutdown();

    return 0;
}

Ship* CreatePlayer() {
  Ship* makePlayer = new Ship();
  makePlayer->SetSprite(CreateSprite(TEXTURE_SPRITE_PLAYER, 64, 32, DRAW_FROM_CENTER), 64, 32);
  makePlayer->SetPosMax(WINDOW_W, WINDOW_H);
  makePlayer->SetPos(WINDOW_W / 2.f, 50);
  makePlayer->SetKeys(GLFW_KEY_A, GLFW_KEY_D, GLFW_KEY_SPACE);

  return makePlayer;
}

Ship* CreateAliens(unsigned int rows, unsigned int columns) {
  Ship* makeAliens = new Ship[(rows*columns)];
  for(unsigned int i=0; i < rows*columns; ++i) {
    makeAliens[i].SetSprite(CreateSprite(TEXTURE_SPRITE_ALIEN, 64, 32, DRAW_FROM_CENTER), 64, 32);
    makeAliens[i].SetPosMax(WINDOW_W, WINDOW_H);
    makeAliens[i].SetPos(WINDOW_W / 2.f, WINDOW_H - (10*i));
  }

  return makeAliens;
}

#include "AIE.h"
#include <iostream>
#include <array>
#include "Bullet.h"
#include "Score.h"
#include "Ship.h"

using namespace std;



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
Ship* CreateAlien();
bool AlienCanMove(array<Ship*, (ENEMY_ROWS*ENEMY_COLUMNS)> &theAliens, bool goRight, float deltaTime);






int main( int argc, char* argv[] )
{
    // Init the AIE Framework
    Initialise(WINDOW_W, WINDOW_H, WINDOW_FULLSCREEN, CHARS_GAME_NAME);
    SetBackgroundColour(SColour(0, 0, 0, 255));
    AddFont(CHARS_GAME_FONT);
    float deltaTime;

    // Set up the Enmus
    GAME_MODE GameMode = MAINMENU;
    ALIEN_DIRECTION AlienDirection = LEFT;

    // Pointers for player/aliens
    Ship* player;
    array<Ship*, (ENEMY_ROWS*ENEMY_COLUMNS)> aliens;

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
            for(unsigned int r = 0; r<ENEMY_ROWS; ++r) {
              for(unsigned int c = 0; c<ENEMY_COLUMNS; ++c) {
                unsigned int i = ( r * ENEMY_COLUMNS ) + c; // Keeps track of which alien we are on. Ranges from 0 to ENEMY_ROWS*ENEMY_COLUMNS
                aliens[i] = CreateAlien();
                (*(aliens[i])).y = ( WINDOW_H - ( (*(aliens[i])).h * r+1) - (*(aliens[i])).h ); // Place our aliens from the top of the screen downards
                (*(aliens[i])).x = (WINDOW_W / (ENEMY_COLUMNS+1) +( WINDOW_W / (ENEMY_COLUMNS+1) * c+1)); //Evenly space the aliens on the x axis
              }
            }

            // And begin the game
            GameMode = PLAY;
            ClearScreen();
            break;

          case PLAY:
            //Check for player input
            if( IsKeyDown((*player).keyLeft)) { (*player).MoveX(deltaTime, false); }
            if( IsKeyDown((*player).keyRight)) { (*player).MoveX(deltaTime, true); }
            //if( IsKeyDown( (*player).keyShoot ) {}

            //Check if aliens can move left/right
            switch(AlienDirection) {
              case LEFT:
				  if (AlienCanMove(aliens, false, deltaTime)){ // Check that alien can move left
                  for(unsigned int i=0; i<ENEMY_COLUMNS*ENEMY_ROWS; ++i) {
                    (*(aliens[i])).MoveX(deltaTime, false); // If yes, move everything left
                  }
                } else {
                  for(unsigned int i=0; i<ENEMY_COLUMNS*ENEMY_ROWS; ++i) {
                    (*(aliens[i])).MoveY(deltaTime, false, 15.f); // If ANY alien can't move left move down that set direction to right
                    AlienDirection = RIGHT;
                  }
                }

                break;

              case RIGHT:
				  if (AlienCanMove(aliens, true, deltaTime)){ // Check that alien can move right
                  for(unsigned int i=0; i<ENEMY_COLUMNS*ENEMY_ROWS; ++i) {
                    (*(aliens[i])).MoveX(deltaTime, true); // If yes, move everything right
                  }
                } else {
                  for(unsigned int i=0; i<ENEMY_COLUMNS*ENEMY_ROWS; ++i) {
                    (*(aliens[i])).MoveY(deltaTime, false, 15.f); // If ANY alien can't move right move down that set direction to left
                    AlienDirection = LEFT;
                  }
                }

                break;
            }

            //Move left/right if possible

            for(unsigned int i=0; i<ENEMY_COLUMNS*ENEMY_ROWS; ++i) {
              MoveSprite((*(aliens[i])).sprite, (*(aliens[i])).x, (*(aliens[i])).y);
              DrawSprite((*(aliens[i])).sprite);
            }

            MoveSprite((*player).sprite, (*player).x, (*player).y);
            DrawSprite((*player).sprite);

            if( IsKeyDown( GLFW_KEY_ESCAPE ) ) { GameMode = CLEANUP; }
            if( IsKeyDown( GLFW_KEY_TAB ) ) { GameMode = CLEANUP; }

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
            cout << player;

      			for (unsigned int i = 0; i<ENEMY_ROWS*ENEMY_COLUMNS; ++i) {
              DestroySprite((*(aliens[i])).sprite);
      				delete aliens[i];
            }

            doExit = true;

            ClearScreen();
            break;

          case QUIT:
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
  makePlayer->SetSpeed(300.f);

  return makePlayer;
}

Ship* CreateAlien() {
  Ship* makeAlien = new Ship();
  makeAlien->SetSprite(CreateSprite(TEXTURE_SPRITE_ALIEN, 64, 32, DRAW_FROM_CENTER), 64, 32);
  makeAlien->SetPosMax(WINDOW_W, WINDOW_H);
  makeAlien->SetPos(WINDOW_W / 2.f, WINDOW_H - (10));
  makeAlien->SetSpeed(150.f);

  return makeAlien;
}

bool AlienCanMove(array<Ship*, (ENEMY_ROWS*ENEMY_COLUMNS)> &theAliens, bool goRight, float deltaTime) {
  bool canMove = true; // Assume the aliens can move
  for(unsigned int i=0; i<ENEMY_COLUMNS*ENEMY_ROWS; ++i) { // Check if each alien can move
    if(canMove && goRight) { // If one of the previous checks already returned false then we're done here
		if ((*(theAliens[i])).x + ((*(theAliens[i])).w / 2) + ((*(theAliens[i])).speed*deltaTime) > (*(theAliens[i])).xMax) { canMove = false; } // If moving would go over the max then we can't move that way
    } else if (canMove && !goRight) {
		if ((*(theAliens[i])).x - ((*(theAliens[i])).w / 2) - ((*(theAliens[i])).speed*deltaTime) < 0) { canMove = false; } // If moving would go under the min then we can't move that way
    }
  }
  return canMove;
}

#pragma once

#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 720

#define EPSILON 0.00000001
#define ISLESS(a, b, tolerance) ((a - b) < tolerance)
#define ISLESSEQUAL(a, b, tolerance) ((a - b) <= tolerance)
#define ISEQUAL(a, b, tolerance) ((a) = (b + tolerance))
#define ISGREATER(a, b, tolerance) ((a) > (b + tolerance))

//Spalsh screen state defines
#define SPLASH_STATE_SHOW_TIME 0.5
#define SPLASH_SCREEN_BACKGROUND_FILEPATH "resources/res/SplashBackground.png"

//Main menu state defines
#define MAIN_MENU_TITLE_PATH "resources/res/GameTitle.png"
#define MAIN_MENU_PLAY_BUTTON "resources/res/PlayButton.png"
#define MAIN_MENU_PLAY_BUTTON_OUTER "resources/res/PlayButtonOuter.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "resources/res/MainMenuBackground.png"

//Game state defines
#define GAME_PAUSE_BUTTON "reosurces/res/PauseButton.png"
#define GAME_BACKGROUND_FILEPATH "resources/res/GameBackground.png"

#define X_PIECE_FILEPATH "resources/res/X.png" 
#define O_PIECE_FILEPATH "resources/res/O.png"
#define X_PIECE_WINNING_FILEPATH "resources/res/XWin.png"
#define O_PIECE_WINNING_FILEPATH "resources/res/OWin.ong"

#define X_PIECE 8
#define O_PIECE 0
#define EMPTY_PIECE -1
#define PLAYER_PIECE X_PIECE
#define AI_PIECE O_PIECE

#define STATE_PLAYING 100
#define STATE_PAUSED 101
#define STATE_WON 102
#define STATE_LOSE 103
#define STATE_PLACING_PIECE 104
#define STATE_AI_PLAYING 105
#define STATE_DRAW 106

//Pause state defines
#define HOME_BUTTON "reosurces/res/HomeButton.png"
#define RESUME_BUTTON "reosurces/res/ResumeButton.png"
#define PAUSE_BACKGROUND_FILEPATH "resources/res/MainMenuBackground.png"

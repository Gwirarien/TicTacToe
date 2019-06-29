#pragma once
#include <string>

const int SCREEN_WIDTH = 768;
const int SCREEN_HEIGHT = 1136;
const double EPSILON = 0.00000001;

constexpr bool ISLESS(const double& a, const double& b, const double& tolerance)
{
	return (a - b) < tolerance;
}

constexpr bool ISLESSEQUAL(const double& a, const double& b, const double& tolerance)
{
	return (a - b) <= tolerance;
}

constexpr bool ISEQUAL(const double& a, const double& b, const double& tolerance)
{
	return a == (b + tolerance);
}

constexpr bool ISGREATER(const double& a, const double& b, const double& tolerance)
{
	return a > (b + tolerance);
}

//Spalsh screen state defines
const double SPLASH_STATE_SHOW_TIME = 0.5;
const std::string SPLASH_SCREEN_BACKGROUND_FILEPATH = "resources/res/SplashBackground.png";

//Main menu state defines
const std::string MAIN_MENU_TITLE_PATH = "resources/res/GameTitle.png";
const std::string MAIN_MENU_PLAY_BUTTON = "resources/res/PlayButton.png";
const std::string MAIN_MENU_PLAY_BUTTON_OUTER = "resources/res/PlayButtonOuter.png";
const std::string MAIN_MENU_BACKGROUND_FILEPATH = "resources/res/MainMenuBackground.png";

//Game state defines
const std::string GAME_PAUSE_BUTTON = "resources/res/PauseButton.png";
const std::string GAME_BACKGROUND_FILEPATH = "resources/res/GameBackground.png";

const std::string X_PIECE_FILEPATH = "resources/res/X.png";
const std::string O_PIECE_FILEPATH = "resources/res/O.png";
const std::string X_PIECE_WINNING_FILEPATH = "resources/res/XWin.png";
const std::string O_PIECE_WINNING_FILEPATH = "resources/res/OWin.png";

const char X_PIECE = 8;
const char O_PIECE = 0;
const char EMPTY_PIECE = -1;
const char PLAYER_PIECE = X_PIECE;
const char AI_PIECE = O_PIECE;

const char STATE_PLAYING = 100;
const char STATE_PAUSED = 101;
const char STATE_WON = 102;
const char STATE_LOSE = 103;
const char STATE_PLACING_PIECE = 104;
const char STATE_AI_PLAYING = 105;
const char STATE_DRAW = 106;

//Pause state defines
const std::string HOME_BUTTON = "resources/res/HomeButton.png";
const std::string RESUME_BUTTON = "resources/res/ResumeButton.png";
const std::string PAUSE_BACKGROUND_FILEPATH = "resources/res/MainMenuBackground.png";

//Game over defines 
const std::string RETRY_BUTTON = "resources/res/RetryButton.png";

//Grid defines
const std::string GRID_SPRITE_FILEPATH = "resources/res/Grid.png";
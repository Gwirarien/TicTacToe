#pragma once

#define SCREEN_WIDTH 680
#define SCREEN_HEIGHT 1080

#define EPSILON 0.00000001
#define ISLESS(a, b, tolerance) ((a - b) < tolerance)
#define ISLESSEQUAL(a, b, tolerance) ((a - b) <= tolerance)
#define ISEQUAL(a, b, tolerance) ((a) = (b + tolerance))
#define ISGREATER(a, b, tolerance) ((a) > (b + tolerance))

#define SPLASH_STATE_SHOW_TIME 0.5
#define SPLASH_SCREEN_BACKGROUND_FILEPATH "resources/res/SplashBackground.png"

#define MAIN_MENU_TITLE_PATH "resources/res/GameTitle.png"
#define MAIN_MENU_PLAY_BUTTON "resources/res/PlayButton.png"
#define MAIN_MENU_PLAY_BUTTON_OUTER "resources/res/PlayButtonOuter.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "resources/res/MainMenuBackground.png"


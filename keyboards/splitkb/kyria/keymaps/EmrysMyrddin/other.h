#include <stdio.h>
#include QMK_KEYBOARD_H

typedef union {
    uint32_t raw;
    struct {
        bool osIsWindows;
    };
} user_config_t;

user_config_t user_config;

enum layers {
    CMK = 0,
    CMK_R,
    WIN,
    LWR,
    RSE,
    LWR_R,
    RSE_R,
    WIN_RSE_LWR,
    GAME,
    GAME_NUM,
    GAME_ARROWS
};

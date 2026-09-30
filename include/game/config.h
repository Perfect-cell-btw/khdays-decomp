#ifndef GAME_CONFIG_H
#define GAME_CONFIG_H

/* The Config page's options (camp menu > Config), as the game-state fields GameState_GetField and
 * GameState_SetField read and write them. Each value is the index of the option the page shows
 * selected, in the page's order (Ov025_Config_LoadValues): 0 is the first option listed. */

#define CONFIG_CONTROLS         0x37c4  /* 1 bit: Type A / Type B (L and R's camera, lock-on, shortcuts) */
#define CONFIG_CHASE_CAM        0x37bf  /* 1 bit: Auto / Manual */
#define CONFIG_CAM_SPEED        0x37c0  /* 2 bits: Slow / Normal / Fast */
#define CONFIG_CAM_X_AXIS       0x37c3  /* 1 bit: Normal / Inverted */
#define CONFIG_CAM_Y_AXIS       0x37c2  /* 1 bit: Normal / Inverted */
#define CONFIG_CURSOR_POSITION  0x37c5  /* 1 bit: Revert / Stay (the command deck's cursor) */
#define CONFIG_COMMAND_LIST     0x37c6  /* 1 bit: X + D-pad / X only */

#endif /* GAME_CONFIG_H */

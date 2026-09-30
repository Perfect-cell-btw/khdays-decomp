/* Allows (non-zero) or forbids the pause menu: PauseMenu_PollInput and Game_EnterPauseScene only
 * open it while this byte (gPauseAllowed) or game flag 0x20ef is set. */

extern int gPauseMode;

void PauseMenu_SetAllowed(char allowed) {
    *(char *)((char *)&gPauseMode + 1) = allowed;
}

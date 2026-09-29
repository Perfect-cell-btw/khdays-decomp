/* Allows (non-zero) or forbids the pause menu: PauseMenu_PollInput and Game_EnterPauseScene only
 * open it while this byte (data_0204bd85) or game flag 0x20ef is set. */

extern int data_0204bd84;

void PauseMenu_SetAllowed(char allowed) {
    *(char *)((char *)&data_0204bd84 + 1) = allowed;
}

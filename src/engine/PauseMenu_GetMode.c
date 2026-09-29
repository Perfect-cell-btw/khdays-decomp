/* Returns the pause mode the main loop runs in (data_0204bd84, set by Callbacks_SetByte):
 * 0 = objects update, 1 = only the pause callbacks run, 2 = both. */

extern int data_0204bd84;

int PauseMenu_GetMode(void) {
    return *(unsigned char *)&data_0204bd84;
}

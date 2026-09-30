/* Clears the two three-word tables and the two flag bytes, and returns 1.
 * The zero stored everywhere is taken FROM the loop counter (`z = i`), which is how the
 * ROM gets its `mov r2, r3` instead of a second `mov #0`. */
extern int gPauseHooks[];
extern int gPauseHookArgs[];
extern char gPauseMode[];

int Callbacks_Init(void) {
    int i = 0;
    int z = i;
    do {
        gPauseHooks[i] = z;
        gPauseHookArgs[i] = z;
        i = i + 1;
    } while (i < 3);
    gPauseMode[0] = (char)z;
    gPauseMode[1] = (char)z;
    return 1;
}

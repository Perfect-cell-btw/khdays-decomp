/* Stores a pair of values into two parallel global arrays. */

extern int gPauseHooks[];
extern int gPauseHookArgs[];
void setDualArrayEntry(int i, int v1, int v2) {
    gPauseHooks[i] = v1;
    gPauseHookArgs[i] = v2;
}

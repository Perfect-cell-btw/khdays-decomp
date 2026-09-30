/* Runs callback slot index with its registered argument, if set. */

extern void (*gPauseHooks[])(void *ptr);
extern void *gPauseHookArgs[];

void Callbacks_Run(int index) {
    void (*callback)(void *ptr) = gPauseHooks[index];

    if (callback != 0) {
        callback(gPauseHookArgs[index]);
    }
}

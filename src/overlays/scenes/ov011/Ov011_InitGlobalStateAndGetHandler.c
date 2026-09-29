/* Once the stream has stopped, sets the title state to 5 and returns the title menu step. */

#include "game/engine.h"

extern int data_ov011_0205e960;
extern void Ov011_TickTitleMenu();

void *Ov011_InitGlobalStateAndGetHandler(void) {
    if (SoundStrm_HasPlaybackPos(0) != 0) return 0;
    *(int *)(*(int *)((char *)&data_ov011_0205e960 + 4) + 4) = 5;
    return (void *)Ov011_TickTitleMenu;
}

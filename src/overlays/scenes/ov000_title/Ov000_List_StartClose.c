/* Ov000_List_StartClose -- (re)build the logo text window, ov000. Refreshes the display
 * (PlaySound), lays out the text buffer @ctx+0xd118 (Tween_Configure/Tween_Start),
 * and arms the window state @ctx+0x966a = 2. */

#include "game/engine.h"

extern void Tween_Configure(void *buf, int, int, int, int);
extern void Tween_Start(void *buf);
void Ov000_List_StartClose(char *ctx) {
    PlaySound(0, 3);
    Tween_Configure(ctx + 0xd118, 0, 0, 0x1000, 0x1f4);
    Tween_Start(ctx + 0xd118);
    *(short *)(ctx + 0x966a) = 2;
}

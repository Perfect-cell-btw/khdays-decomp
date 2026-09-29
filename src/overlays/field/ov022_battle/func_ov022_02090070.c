/* Draws the current sub-object's node when it belongs to the local player's group. */

#include "game/engine.h"

extern int Ov022_GetEntryField66(unsigned int arg0);
extern void func_ov022_0208ffe8(unsigned short *arg0, int arg1);
void func_ov022_02090070(int arg0, int arg1, int arg2, int arg3) {
    int t = *(int *)(arg0 + *(int *)(arg0 + 0xc) * 4 + 0x18);
    if (*(char *)(t + 0x110) != Ov022_GetEntryField66(QueryActiveStateOrDelegate())) return;
    if (Ov022_GetEntryField66(QueryActiveStateOrDelegate()) == -1) return;
    func_ov022_0208ffe8((unsigned short *)(t + 8), 0xffffffff);
}

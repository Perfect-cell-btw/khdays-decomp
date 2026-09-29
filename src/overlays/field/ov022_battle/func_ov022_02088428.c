/* Shows a player's render entity for a group and records the group. */

#include "game/engine.h"

extern void Entity_SetVisible(int arg0, int arg1);
extern int data_02041dc8;
void func_ov022_02088428(int arg0, int arg1) {
    int e = GetEntryField20ByIndex(arg0);
    if (e == 0) return;
    Entity_SubmitRenderNode(*(char *)(e + 0x4bc), (unsigned short)arg1, 0, (int)&data_02041dc8);
    Entity_SetVisible(*(char *)(e + 0x4bc), 1);
    *(unsigned short *)(e + 0x66) = arg1;
}

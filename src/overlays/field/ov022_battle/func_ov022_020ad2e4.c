/* Places a state marker at the actor when it is the local player's and on the local player's side.
 */

#include "game/engine.h"

extern int Ov022_GetEntryField66(unsigned int arg0);
extern void Ov022_PlaceStateMarker(int arg0, unsigned int arg1, int arg2, int *arg3);

void func_ov022_020ad2e4(int arg0, int arg1) {
    if (*(unsigned char *)(arg0 + 8) != Session_GetLocalPlayerIndex()) return;
    if (Ov022_GetEntryField66(QueryActiveStateOrDelegate()) !=
        Ov022_GetEntryField66(*(unsigned char *)(arg0 + 9))) return;
    Ov022_PlaceStateMarker(0, *(unsigned char *)(arg0 + 9), arg1, (int *)(arg0 + 0x48c));
}

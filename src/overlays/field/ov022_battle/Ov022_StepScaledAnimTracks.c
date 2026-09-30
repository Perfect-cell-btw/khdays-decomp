/* On the host only, steps the actor's node animation tracks (Sequence_UpdateTracks) by its
 * animation step (+0x2aba) while its speed is not the normal one (bit 6 of the node flags, set
 * by Ov022_SetAnimSpeed). */

#include "game/engine.h"

extern void Sequence_UpdateTracks(unsigned short *actor, int arg1);
void Ov022_StepScaledAnimTracks(int actor) {
    unsigned int *p;
    if (Session_GetLocalPlayerIndex() != 0) return;
    p = *(unsigned int **)(actor + 0x20);
    if ((*p & 0x40) == 0) return;
    Sequence_UpdateTracks((unsigned short *)(p + 1), *(short *)(actor + 0x2aba));
}

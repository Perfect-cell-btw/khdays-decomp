/*
 * Per-frame update of the actor's UI anchor: reads the model's current frame, drives the
 * primary channel (+0xda8 with the +0x2c2c config) at the actor's heading, refreshes the rig
 * (020b4c50) for the current owner and, for the local player, queues action 3/1 once a
 * puppet-free actor (bit 16 clear) in mode 0x30 reaches tick 0xf000. Finally 020ad588 runs.
 */

#include "game/engine.h"

extern void Ov002_WidgetScrollCommit(char *channel, char *config, int heading, int frame);
extern int Ov022_GetGlobal34(void);
extern void Ov055_PushPartsArgAndRefresh(char *self, int owner);
extern void func_ov022_020ad588(char *self);

void Ov055_UpdateAnchor(char *self)
{
    int frame = Anim_GetFrame(*(char **)(self + 0x20) + 4, 0);

    Ov002_WidgetScrollCommit(self + 0x1a8 + 0xc00, self + 0x2c + 0x2c00, *(short *)(self + 0x2aba), frame);
    Ov055_PushPartsArgAndRefresh(self, Ov022_GetGlobal34());
    if (Session_GetLocalPlayerIndex() == 0 && (*(int *)self & 0x10000) == 0 && *(int *)(self + 0x6bc) == 0x30
        && *(int *)(self + 0x7b0) == 0xf000) {
        *(unsigned char *)(self + 0x47a) = 3;
        *(unsigned char *)(self + 0x47b) = 1;
    }
    func_ov022_020ad588(self);
}

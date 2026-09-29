/* Draw hook of the ov269 enemy (and its byte-identical twins): refreshes the +0x3d0 sub-node, runs the
 * ov107 base draw, copies the +0x394 item's +4 placement into the actor's +0x3a4 slot and
 * scales that copy to 0x28cc (the Ov120_ReleaseAndDestroy shape with a placement mirror). */

#include "game/enemy_common.h"

typedef struct { int w[11]; } Placement;

extern void Ov107_ProcessObjectTick(int *self, int arg);
extern void Srt_SetScaleUniform(Placement *placement, int scale);

void Ov269_Draw(int *self, int arg)
{
    Ov107_RefreshAndSelectChild(self[0xf4], arg);
    Ov107_ProcessObjectTick(self, arg);
    *(Placement *)(self + 0xe9) = *(Placement *)(self[0xe5] + 4);
    Srt_SetScaleUniform((Placement *)(self + 0xe9), 0x28cc);
}

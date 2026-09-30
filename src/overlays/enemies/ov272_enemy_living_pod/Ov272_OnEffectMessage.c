/* Effect message hook of the ov272 enemy (variant of ov119/ov279's). A "spawned" message (kind 5)
 * picks by byte 3: slots 0/1 spawn pair 2 (kind 0x15, scale 1.5) at the packed position (bytes 5..) and, clearing
 * (slot 0) or raising (slot 1) bit 4 of +0x1ae, restart the +0x3a4 aura (Ov272_SpawnChildStoreSelfAndArg with
 * the slot); slot 2 spawns pair 1 (kind 5, scale 1.5) at the packed position; slot 3 spawns pair 4 on
 * the +0xa0 pose; slot 4 anchors pair 3 on the pose
 * (looping). The base hook always runs. */

#include "nitro/types.h"
#include "game/enemy_common.h"

struct Pair { int res; int handle; };

extern int Ov107_CreateNodeXformTaskFx24(int model, int res, int kind, int arg, int scale, void *pos);
extern int Ov107_CreateNodeXformTask(int model, int res, int kind, int zero, void *t);
extern int Ov272_SpawnChildStoreSelfAndArg(char *self, int on);
extern void Ov107_AiState_OnMessage(char *self, u8 *msg, int arg);

void Ov272_OnEffectMessage(char *self, u8 *msg, int arg)
{
    if (msg[2] == 5) {
        switch (msg[3]) {
        case 0:
        case 1:
            (*(struct Pair **)(self + 0x3a8))[2].handle =
                Ov107_CreateNodeXformTaskFx24(*(int *)(self + 0x3c), (*(struct Pair **)(self + 0x3a8))[2].res, 0x15, 0, 0x1800, msg + 5);
            if (msg[3] == 0) {
                *(u16 *)(self + 0x1ae) &= ~0x10;
                *(int *)(self + 0x3a4) = Ov272_SpawnChildStoreSelfAndArg(self, 0);
            } else {
                *(u16 *)(self + 0x1ae) |= 0x10;
                *(int *)(self + 0x3a4) = Ov272_SpawnChildStoreSelfAndArg(self, 1);
            }
            break;
        case 2:
            (*(struct Pair **)(self + 0x3a8))[1].handle =
                Ov107_CreateNodeXformTaskFx24(*(int *)(self + 0x3c), (*(struct Pair **)(self + 0x3a8))[1].res, 5, 0, 0x1800, msg + 5);
            break;
        case 3:
            (*(struct Pair **)(self + 0x3a8))[4].handle =
                Ov107_CreateNodeXformTask(*(int *)(self + 0x3c), (*(struct Pair **)(self + 0x3a8))[4].res, 5, 0, self + 0xa0);
            break;
        case 4:
            (*(struct Pair **)(self + 0x3a8))[3].handle =
                Ov107_CreateNodeBodyTask(*(int *)(self + 0x3c), (*(struct Pair **)(self + 0x3a8))[3].res, 5, self + 0xa0, 0, 1);
            break;
        }
    }
    Ov107_AiState_OnMessage(self, msg, arg);
}

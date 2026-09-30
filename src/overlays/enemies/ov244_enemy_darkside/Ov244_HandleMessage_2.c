/* Message handler of the ov114 enemy. A kind-0 message stores its +0x24 word into +0x390 (the
 * item's Y scale), scales the +0x384 item's +4 placement to (1.0, that, 1.0) and clears the
 * subscriber's state; a "spawned" message (kind 5) starts the sub-item of the +0x394 set picked
 * by the sub-kind (0 -> entry 0, 1 -> entry 2) through ov107::020c08cc (mode 0x17, weight
 * 0x1000, the packet's payload) and keeps the handle in the following entry, or for sub-kind 2
 * registers effect 0x112 (kind 7) on the +0xa0 node into +0x398. The base handler always runs. */

#include "game/enemy_common.h"

extern void Srt_SetScaleXYZ(void *placement, int x, int y, int z);
extern void RefreshObjectCallbacks(int subscriber, int a);
extern void *Ov107_CreateNodeXformTaskFx24(void *taskList, void *subitem, int mode, int blend, int weight, void *payload);
extern void Ov107_AiState_OnMessage(int actor, unsigned char *msg, int param);

void Ov244_HandleMessage_2(int actor, unsigned char *msg, int param)
{
    if (msg[2] == 0) {
        *(int *)(actor + 0x390) = *(int *)(msg + 0x24);
        Srt_SetScaleXYZ((void *)(*(int *)(actor + 0x384) + 4), 0x1000, *(int *)(actor + 0x390), 0x1000);
        RefreshObjectCallbacks(*(int *)(actor + 0x9c), 0);
    } else if (msg[2] == 5) {
        switch (msg[3]) {
        case 0:
            (*(void ***)(actor + 0x394))[1] =
                Ov107_CreateNodeXformTaskFx24(*(void **)(actor + 0x3c), (*(void ***)(actor + 0x394))[0], 0x17, 0, 0x1000, msg + 5);
            break;
        case 1:
            (*(void ***)(actor + 0x394))[3] =
                Ov107_CreateNodeXformTaskFx24(*(void **)(actor + 0x3c), (*(void ***)(actor + 0x394))[2], 0x17, 0, 0x1000, msg + 5);
            break;
        case 2:
            *(int *)(actor + 0x398) = Ov107_CreateSpawnTask(actor, 0x112, 7, 0, (void *)(actor + 0xa0));
            break;
        }
    }
    Ov107_AiState_OnMessage(actor, msg, param);
}

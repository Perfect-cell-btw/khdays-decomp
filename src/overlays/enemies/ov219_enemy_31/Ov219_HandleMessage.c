/* Message handler of the ov219 enemy: a "spawned" message (kind 5) starts the sub-item of the
 * +0x3c4 node slot named by the packet (payload 0: through ov107::020c08cc with mode 5 and weight
 * 0x14cd, payloads 1/2: through ov107::020c09a0 at the +0x398 transform, kind 0x11 plus 4 for
 * payload 2) and keeps the handle at +0x3c8; payload 4 finishes the handle named by the packet.
 * The base handler always runs. */

#include "nitro/types.h"

extern void *Ov107_CreateNodeXformTaskFx24(void *taskList, void *subitem, int mode, int blend, int weight, void *payload);
extern void *Ov107_CreateNodeBodyTask(void *taskList, void *subitem, u8 kind, void *at, int a, int b);
extern void TaskList_FinishByTag(void *taskList, void *handle);
extern void Ov107_AiState_OnMessage(int actor, u8 *msg, int param);

void Ov219_HandleMessage(int actor, u8 *msg, int param)
{
    if (msg[2] == 5) {
        switch (msg[3]) {
        case 0:
            *(void **)(actor + msg[3] * 8 + 0x3c8) =
                Ov107_CreateNodeXformTaskFx24(*(void **)(actor + 0x3c), *(void **)(actor + msg[3] * 8 + 0x3c4), 5, 0, 0x14cd, msg + 5);
            break;
        case 1:
        case 2:
            *(void **)(actor + msg[3] * 8 + 0x3c8) =
                Ov107_CreateNodeBodyTask(*(void **)(actor + 0x3c), *(void **)(actor + msg[3] * 8 + 0x3c4),
                                    (msg[3] == 2 ? 4 : 0) | 0x11, (void *)(actor + 0x398), 0, 1);
            break;
        case 4:
            if (*(void **)(actor + msg[4] * 8 + 0x3c8) != 0) {
                TaskList_FinishByTag(*(void **)(actor + 0x3c), *(void **)(actor + msg[4] * 8 + 0x3c8));
                *(void **)(actor + msg[4] * 8 + 0x3c8) = 0;
            }
            break;
        }
    }
    Ov107_AiState_OnMessage(actor, msg, param);
}

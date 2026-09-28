/* Effect message hook of the ov231 enemy (x5 with ov232/ov263/ov265/ov280). A "spawned" message (kind 5) picks
 * the +0x3b8 pair named by byte 3: slots 0/2 spawn at the packed position (bytes 5..) with mode 5
 * (slot 0) or 1 and weight 0x1119 / 0x1119; the other slots first finish the pending slot-6 effect
 * and then anchor on the +0x3dc point with kind 0x15 (slot 4) or 5, looping for slot 6. The base
 * hook always runs. */

#include "nitro/types.h"

struct Pair { void *res; void *handle; };

extern int FX_Div(int num, int den);
extern void *Ov107_CreateNodeXformTaskFx24(void *taskList, void *subitem, int mode, int blend,
                                           int weight, void *payload);
extern void *Ov107_CreateNodeBodyTask(void *taskList, void *subitem, int kind, void *at, int a,
                                      int b);
extern void TaskList_FinishByTag(void *taskList, void *handle);
extern void Ov107_AiState_OnMessage(char *actor, u8 *msg, int param);

void Ov231_OnEffectMessage(char *actor, u8 *msg, int param)
{
    int weight;

    if (msg[2] == 5) {
        weight = FX_Div(0x1119, 0x1119);
        switch (msg[3]) {
        case 0:
        case 2:
            (*(struct Pair **)(actor + 0x3b8))[msg[3]].handle =
                Ov107_CreateNodeXformTaskFx24(*(void **)(actor + 0x3c),
                                              (*(struct Pair **)(actor + 0x3b8))[msg[3]].res,
                                              (u8)(msg[3] == 0 ? 5 : 1), 0, weight, msg + 5);
            break;
        case 1:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            {
                u8 kind = msg[3] == 4 ? 0x15 : 5;
                if ((*(struct Pair **)(actor + 0x3b8))[6].handle != 0) {
                    TaskList_FinishByTag(*(void **)(actor + 0x3c), (*(struct Pair **)(actor + 0x3b8))[6].handle);
                    (*(struct Pair **)(actor + 0x3b8))[6].handle = 0;
                }
                (*(struct Pair **)(actor + 0x3b8))[msg[3]].handle =
                    Ov107_CreateNodeBodyTask(*(void **)(actor + 0x3c),
                                             (*(struct Pair **)(actor + 0x3b8))[msg[3]].res,
                                             (u8)kind, actor + 0x3dc, 0, msg[3] == 6);
            }
            break;
        }
    }
    Ov107_AiState_OnMessage(actor, msg, param);
}

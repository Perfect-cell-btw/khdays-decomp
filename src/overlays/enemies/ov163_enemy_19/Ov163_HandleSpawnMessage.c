/* Ov163_HandleSpawnMessage: ported from a matched sibling family (same shape, constants and offsets adjusted). */

#include "game/enemy_common.h"

extern int Ov163_SpawnChild0cAndBackLink(int, int, int, int);
extern int Ov107_CreateNodeXformTaskFx24(int, int, int, int, int, int);
extern int Ov163_SpawnChild10AndBackLink(int, int, int, int);
extern void Ov107_AiState_OnMessage(int, int, int);
void Ov163_HandleSpawnMessage(int param_1, int param_2, int param_3, int param_4) {
    int result;
    if (*(unsigned char *)(param_2 + 2) == 0x5) {
        switch (*(unsigned char *)(param_2 + 3)) {
        case 0:
            if (*(int *)(*(int *)(param_1 + 0x3c4) + 4) == 0) {
                result = Ov163_SpawnChild0cAndBackLink(param_1, *(int *)(*(int *)(param_1 + 0x3c4) + 4),
                                             param_3, param_4);
                *(int *)(*(int *)(param_1 + 0x3c4) + 4) = result;
            }
            result = Ov107_CreateSpawnTask(param_1, 0x153, 4, 0,
                                         *(int *)(param_1 + 0x3c0) + 4);
            *(int *)(param_1 + 0x3d0) = result;
            break;
        case 1:
            result = Ov107_CreateNodeXformTaskFx24(*(int *)(param_1 + 0x3c),
                                         *(int *)(*(int *)(param_1 + 0x3c4) + 8),
                                         0x5, 0, 0x1000, param_2 + 5);
            *(int *)(*(int *)(param_1 + 0x3c4) + 0xc) = result;
            break;
        case 2:
            break;
        case 3:
            result = Ov107_CreateNodeXformTaskFx24(*(int *)(param_1 + 0x3c),
                                         *(int *)(*(int *)(param_1 + 0x3c4) + 0x10),
                                         0x5, *(unsigned char *)(param_2 + 4), 0x1800, param_2 + 5);
            *(int *)(*(int *)(param_1 + 0x3c4) + 0x14) = result;
            Ov107_ForwardVisibleEvent(param_1, 1);
            break;
        case 4:
            result = Ov163_SpawnChild10AndBackLink(param_1, *(unsigned char *)(param_2 + 3), param_3, param_4);
            *(int *)(*(int *)(param_1 + 0x3c4) + 0x1c) = result;
            result = Ov107_CreateNodeBodyTask(*(int *)(param_1 + 0x3c),
                                         *(int *)(*(int *)(param_1 + 0x3c4) + 0x20),
                                         0x15, param_1 + 0x394, 0, 1);
            *(int *)(*(int *)(param_1 + 0x3c4) + 0x24) = result;
            break;
        }
    }
    Ov107_AiState_OnMessage(param_1, param_2, param_3);
}

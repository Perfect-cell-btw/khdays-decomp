/* Effect message (kind 5): spawns the child or the effect task for the sub-kind. */

extern int Ov132_SpawnChild0cAndBackLink(int, int, int, int);
extern int Ov107_CreateSpawnTask(int, int, int, int, int);
extern int Ov107_CreateNodeXformTaskFx24(int, int, int, int, int, int);
extern void Ov107_ForwardVisibleEvent(int, int);
extern int Ov132_SpawnChild10AndBackLink(int, int, int, int);
extern int Ov107_CreateNodeBodyTask(int, int, int, int, int, int);
extern void Ov107_AiState_OnMessage(int, int, int);
void Ov132_OnEffectMessage(int param_1, int param_2, int param_3, int param_4) {
    int result;
    if (*(unsigned char *)(param_2 + 2) == 5) {
        switch (*(unsigned char *)(param_2 + 3)) {
        case 0:
            if (*(int *)(*(int *)(param_1 + 0x3c4) + 4) == 0) {
                result = Ov132_SpawnChild0cAndBackLink(param_1, *(int *)(*(int *)(param_1 + 0x3c4) + 4),
                                             param_3, param_4);
                *(int *)(*(int *)(param_1 + 0x3c4) + 4) = result;
            }
            result = Ov107_CreateSpawnTask(param_1, 0x119, 4, 0,
                                         *(int *)(param_1 + 0x3c0) + 4);
            *(int *)(param_1 + 0x3d0) = result;
            break;
        case 1:
            result = Ov107_CreateNodeXformTaskFx24(*(int *)(param_1 + 0x3c),
                                         *(int *)(*(int *)(param_1 + 0x3c4) + 8),
                                         5, 0, 0x1000, param_2 + 5);
            *(int *)(*(int *)(param_1 + 0x3c4) + 0xc) = result;
            break;
        case 2:
            break;
        case 3:
            result = Ov107_CreateNodeXformTaskFx24(*(int *)(param_1 + 0x3c),
                                         *(int *)(*(int *)(param_1 + 0x3c4) + 0x18),
                                         5, *(unsigned char *)(param_2 + 4), 0x1800, param_2 + 5);
            *(int *)(*(int *)(param_1 + 0x3c4) + 0x1c) = result;
            Ov107_ForwardVisibleEvent(param_1, 1);
            break;
        case 4:
            result = Ov132_SpawnChild10AndBackLink(param_1, *(unsigned char *)(param_2 + 3), param_3, param_4);
            *(int *)(*(int *)(param_1 + 0x3c4) + 0x24) = result;
            result = Ov107_CreateNodeBodyTask(*(int *)(param_1 + 0x3c),
                                         *(int *)(*(int *)(param_1 + 0x3c4) + 0x10),
                                         5, param_1 + 0x394, 0, 1);
            *(int *)(*(int *)(param_1 + 0x3c4) + 0x14) = result;
            break;
        }
    }
    Ov107_AiState_OnMessage(param_1, param_2, param_3);
}

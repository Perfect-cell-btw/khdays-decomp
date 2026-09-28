/* Ov006_PollInput -- Mission Mode input poll, ov006. 0 = idle; 2 = attract timeout fired
 * (key 9 + Ov006_IsSceneState0); 1 = Start pressed (key 7). Guarded by the Mission Mode-ready
 * flag data_ov006_02056660. */
extern void *NNSi_FndGetCurrentRootHeap(void);
extern void *data_ov006_02056660;
extern int  Ov006_MissionScene_GetState(void);
extern int  Ov006_IsSceneState0(void);
int Ov006_PollInput(void) {
    NNSi_FndGetCurrentRootHeap();
    if (data_ov006_02056660 == 0) {
        return 0;
    }
    if (Ov006_MissionScene_GetState() == 9 && Ov006_IsSceneState0() != 0) {
        return 2;
    }
    return Ov006_MissionScene_GetState() == 7;
}

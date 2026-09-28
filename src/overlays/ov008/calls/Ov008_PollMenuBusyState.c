/* Ov008_PollMenuBusyState -- Ov008_PollMenuBusyState (108 B, 6 relocs).
 * Returns a small status code describing whether the menu is mid-transition. Returns 0 when the
 * menu-state object data_ov008_02090fa0 is not allocated. Returns 1 when its field2c is set and
 * Ov008_CanConfirmMissionMenu() reports active. Returns 2 when the current scene id (Ov008_MissionScene_GetState)
 * is 9 and Ov008_IsSceneState0() reports active. Otherwise returns whether the scene id is 7.
 * The `data_ov008_02090fa0 != 0` re-test in the second condition is deliberate: it matches the
 * ROM, which reuses the null-check flags to predicate the field2c load (ldrne/cmpne). */
typedef unsigned char u8;

typedef struct Ov008MenuState {
    u8  pad_0000[0x2c];
    int field2c;   /* 0x2c */
} Ov008MenuState;

extern void *NNSi_FndGetCurrentRootHeap(void);
extern Ov008MenuState *data_ov008_02090fa0;
extern int Ov008_CanConfirmMissionMenu(void);
extern int Ov008_MissionScene_GetState(void);
extern int Ov008_IsSceneState0(void);

int Ov008_PollMenuBusyState(void)
{
    NNSi_FndGetCurrentRootHeap();
    if (data_ov008_02090fa0 == 0) {
        return 0;
    }
    if (data_ov008_02090fa0 != 0 && data_ov008_02090fa0->field2c != 0 &&
        Ov008_CanConfirmMissionMenu() != 0) {
        return 1;
    }
    if (Ov008_MissionScene_GetState() == 9 && Ov008_IsSceneState0() != 0) {
        return 2;
    }
    return Ov008_MissionScene_GetState() == 7;
}

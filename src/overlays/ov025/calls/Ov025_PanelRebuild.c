/* Ov025_PanelRebuild -- rebuild the ov025 panel's live sub-views. Clears the "ready" flag
 * (obj[0x141]) while rebuilding each present part, then marks ready and clears the dirty flag
 * (obj[0x140]). */
extern void Ov025_TouchScrollList(unsigned int *obj);
extern void Ov025_ClearSlotUnlessKind1(int obj);
extern void Ov025_MissionListRevealTick(unsigned int *obj);
extern void Ov025_BlinkMissionListDots(int obj);

void Ov025_PanelRebuild(unsigned int *param_1) {
    param_1[0x141] = 0;
    if (param_1[0xc] != 0) {
        Ov025_TouchScrollList(param_1);
    }
    if (param_1[0xd] != 0) {
        Ov025_ClearSlotUnlessKind1((int)param_1);
    }
    if (param_1[0x1a] != 0) {
        Ov025_MissionListRevealTick(param_1);
    }
    if (*(unsigned short *)(param_1 + 0x17) != 0) {
        Ov025_BlinkMissionListDots((int)param_1);
    }
    param_1[0x141] = 1;
    param_1[0x140] = 0;
}

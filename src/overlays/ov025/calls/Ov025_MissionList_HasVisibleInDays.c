/* Whether page A's mission list has a visible mission in the day range. */

extern int Ov025_GetPageA();
extern int Ov025_MissionList_HasVisibleMissionInDays();

void Ov025_MissionList_HasVisibleInDays(int arg0, int arg1) {
    Ov025_MissionList_HasVisibleMissionInDays(Ov025_GetPageA(arg0) + 0x13fc, arg0, arg1);
}

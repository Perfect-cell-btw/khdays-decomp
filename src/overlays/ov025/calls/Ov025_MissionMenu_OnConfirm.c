/* On state 4 of the selection starts the selected mission. */

extern int Ov025_MissionList_StartMission();

void Ov025_MissionMenu_OnConfirm(int arg0, int arg1) {
    if (arg1 == 4 && *(int *)arg0 == 1) {
        Ov025_MissionList_StartMission();
    }
}

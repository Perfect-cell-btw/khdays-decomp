extern void Ov008_StartSelectedMission(int);
void Ov008_MissionMenu_OnConfirm(int *obj, int state)
{
    if (state == 4 && obj[0] == 1) {
        Ov008_StartSelectedMission(obj[0]);
    }
}

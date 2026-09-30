/* Idle input reaction: when nothing is busy and the key is pressed, toggles the mode widgets or
 * pages the mission list. */

extern void Ov008_ApplyModeWidgets(int obj, unsigned int flag);
extern void Ov008_MissionListPage(int *obj, int dir);
extern unsigned short gPadHeld;

void Ov008_TickIdleReaction_Up(int *obj) {
    if (obj[0x1a] == 0 && obj[0xc] == 0 && obj[0xd] == 0) {
        if ((gPadHeld & 0xf0) == 0x10) {
            if (obj[0x13e] != 0) {
                Ov008_ApplyModeWidgets((int)obj, obj[0x13f] == 0);
            } else {
                Ov008_MissionListPage(obj, 1);
            }
        }
    }
}

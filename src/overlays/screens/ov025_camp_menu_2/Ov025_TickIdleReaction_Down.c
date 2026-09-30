/* When the actor is idle (fields 0x1a/0xc/0xd all zero) and the global phase byte is in the 0x20
 * band, start a directed reaction (field 0x13e != 0, dir from 0x13f) or the default down one. */

extern void Ov025_ApplyModeWidgets(int obj, unsigned int flag);
extern void Ov025_MissionListPage(int *obj, int dir);
extern unsigned short gPadHeld;

void Ov025_TickIdleReaction_Down(int *obj) {
    if (obj[0x1a] == 0 && obj[0xc] == 0 && obj[0xd] == 0) {
        if ((gPadHeld & 0xf0) == 0x20) {
            if (obj[0x13e] != 0) {
                Ov025_ApplyModeWidgets((int)obj, obj[0x13f] == 0);
            } else {
                Ov025_MissionListPage(obj, -1);
            }
        }
    }
}

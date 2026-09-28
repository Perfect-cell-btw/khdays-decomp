extern void Ov008_ApplyModeWidgets(int obj, unsigned int flag);
extern void Ov008_MissionListPage(int *obj, int dir);
extern unsigned short data_0204c18c;

void Ov008_TickIdleReaction_Down(int *obj) {
    if (obj[0x1a] == 0 && obj[0xc] == 0 && obj[0xd] == 0) {
        if ((data_0204c18c & 0xf0) == 0x20) {
            if (obj[0x13e] != 0) {
                Ov008_ApplyModeWidgets((int)obj, obj[0x13f] == 0);
            } else {
                Ov008_MissionListPage(obj, -1);
            }
        }
    }
}

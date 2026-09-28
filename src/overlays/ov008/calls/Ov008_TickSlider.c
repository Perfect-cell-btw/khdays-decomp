extern void Ov008_ScrollMissionList(int obj, int delta);
extern unsigned short data_0204c18c;

void Ov008_TickSlider(int param_1) {
    switch (*(int *)(param_1 + 8)) {
    case 1:
        if (data_0204c18c & 0x40) {
            Ov008_ScrollMissionList(param_1, -8);
            return;
        }
        *(int *)(param_1 + 8) = 0;
        return;
    case 2:
        if (data_0204c18c & 0x80) {
            Ov008_ScrollMissionList(param_1, 8);
            return;
        }
        *(int *)(param_1 + 8) = 0;
        return;
    default:
        *(int *)(param_1 + 8) = 0;
    }
}

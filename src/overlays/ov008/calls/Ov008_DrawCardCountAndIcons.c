extern int Ov008_PlaceNodeShape(int p1, char *caption, int a, int p4, int p5, int one);
extern int Ov008_CanPlaceShape(int p1, int count, int a, int p4, int p5);
extern int Ov008_CanPlaceRecord(int p1, int a, unsigned int b, unsigned int c, unsigned int d, int one);

unsigned int Ov008_DrawCardCountAndIcons(int param_1, int param_2, char *param_3, int param_4, int param_5) {
    unsigned int result;
    int ok;
    if (param_2 != 0) {
        if (param_3 != 0) {
            result = Ov008_PlaceNodeShape(param_1, param_3, *(int *)(param_1 + 0x18), param_4, param_5, 1);
        } else {
            result = Ov008_CanPlaceShape(param_1, param_2, *(int *)(param_1 + 0x18), param_4, param_5);
        }
    } else {
        result = 1;
    }
    ok = Ov008_CanPlaceRecord(param_1, *(int *)(param_1 + 0x19b4), *(unsigned int *)(param_1 + 0x18),
                             *(unsigned short *)(param_1 + 0x64), *(unsigned short *)(param_1 + 0x66), 1);
    return result & ok;
}

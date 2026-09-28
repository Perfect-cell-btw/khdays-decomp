extern int Ov008_GetNextMissionEntry_2(int index);
extern int Ov008_GetNextMissionEntry(int node);
extern void Ov008_DrawMissionRow(int obj, int slot, int node);

void Ov008_RefillListRows(int param_1) {
    int node;
    int i;
    int base;
    if (*(int *)(param_1 + 0x68) != 0) {
        return;
    }
    base = *(int *)(param_1 + 0xc) / 32;
    node = Ov008_GetNextMissionEntry_2(base);
    i = 0;
    do {
        if (node == 0) {
            break;
        }
        if (*(int *)(param_1 + 0x7c) != 0 && base + i > (int)*(unsigned short *)(param_1 + 0x6e)) {
            break;
        }
        Ov008_DrawMissionRow(param_1, i, node);
        node = Ov008_GetNextMissionEntry(node);
        i++;
    } while (i < 6);
    *(int *)(param_1 + 0x48) = 1;
}

/* For each variable-stride record, forward its fields to Ov025_BuildTagTrackerNode. */
extern void Ov025_BuildTagTrackerNode(int self, int a, int b, int c, int d, int e, int f);
void Ov025_BuildLayoutFromTagTable(int param_1, int param_2) {
    unsigned int n = *(unsigned int *)param_2;
    unsigned int i;
    int p = param_2 + 4;
    for (i = 0; i < n; i++) {
        Ov025_BuildTagTrackerNode(param_1, *(unsigned short *)(p + 0xc), p + 0x10,
            *(unsigned short *)(p + 0xe), *(int *)(p + 4), *(int *)(p + 8), 0);
        p += *(int *)p;
    }
}

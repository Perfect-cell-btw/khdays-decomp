/* Snapshot +0x6c into +0x64/+0x68, then dispatch via c634 choosing the callback by +0x74. */
extern int SetIndexedSlot(int, int, void *);
extern int Ov260_TickTurn(int);
extern int Ov260_HoverEntry(int);
int Ov260_AiEndCircle(int param_1) {
    int owner = *(int *)(param_1 + 4);
    int v = *(int *)(owner + 0x6c);
    *(int *)(owner + 0x64) = v;
    *(int *)(owner + 0x68) = v;
    return SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20),
        *(int *)(owner + 0x74) < 5 ? (void *)&Ov260_TickTurn : (void *)&Ov260_HoverEntry);
}

extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern unsigned short data_ov269_020d4a34[];
extern void Ov269_stIdlePose7ClearTimerAdvance(void);
void Ov269_stateAnimPairCallback(int *node) {
    int *state = (int *)node[1];
    unsigned short pair[2];
    unsigned short *pp;
    void (*cb)();
    Ov107_PostTagUpdate(*state, 6, 0);
    pp = pair;
    pp[1] = data_ov269_020d4a34[1];
    pp[0] = data_ov269_020d4a34[0];
    cb = *(void (**)())(*state + 0x24);
    if (cb != 0) cb(*state, pp, 4);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov269_stIdlePose7ClearTimerAdvance);
}

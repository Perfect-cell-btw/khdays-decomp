/* Clear bit 1 of the object's +0x5c flags, then dispatch via c634. */
extern int SetIndexedSlot(int, int, void *);
extern int Ov107_FinishIfOwnerIdle(int);
int Ov107_NodeXformTaskStart(int param_1) {
    int obj = *(int *)(*(int *)(param_1 + 4));
    *(int *)(obj + 0x5c) &= ~2;
    return SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov107_FinishIfOwnerIdle);
}

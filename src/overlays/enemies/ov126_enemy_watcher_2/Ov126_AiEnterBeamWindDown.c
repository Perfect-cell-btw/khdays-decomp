/* Clear the owner's +0x30 field, then dispatch via c634. */
extern int SetIndexedSlot(int, int, void *);
extern int Ov126_BeamWindDownTick(int);
int Ov126_AiEnterBeamWindDown(int param_1) {
    *(int *)(*(int *)(param_1 + 4) + 0x30) = 0;
    return SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov126_BeamWindDownTick);
}

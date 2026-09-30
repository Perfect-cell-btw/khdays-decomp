/* Advance the packed nibble state at +0x38: if flagged, clear the pending high nibble; unless the
 * high nibble is empty, copy it down and dispatch the matching handler; finally re-arm it to -1. */
extern int SetIndexedSlot(int, int, void *);
extern int Ov200_AimNode_HideAll(int);
extern int Ov200_AimSubNodeArmRegions(int);
extern int Ov200_AiGoToTimerEaseInterp(int);
struct nibs { int lo : 4, hi : 4; };
void Ov200_AimNode_AiDispatch(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (*(unsigned char *)(*(int *)owner + 0x1c4) & 0xa) {
        if (((struct nibs *)(owner + 0x38))->lo != 0) {
            ((struct nibs *)(owner + 0x38))->hi = 0;
        }
    }
    if (((struct nibs *)(owner + 0x38))->hi != -1) {
        ((struct nibs *)(owner + 0x38))->lo = ((struct nibs *)(owner + 0x38))->hi;
        switch (((struct nibs *)(owner + 0x38))->lo) {
        case 0: SetIndexedSlot(param_1, 1, (void *)&Ov200_AimNode_HideAll); break;
        case 1: SetIndexedSlot(param_1, 1, (void *)&Ov200_AimSubNodeArmRegions); break;
        case 2: SetIndexedSlot(param_1, 1, (void *)&Ov200_AiGoToTimerEaseInterp); break;
        }
    }
    ((struct nibs *)(owner + 0x38))->hi = -1;
}

/* Returns the position of the element's first slot that is set (+0x14, then +0x18). */

extern int Slot_GetPositionPtr(int r0, int r1);

int Ov025_ApplyFirstValidSlot(int r0, int *r1)
{
    int i;
    int result;

    result = -1;
    for (i = 0; i < 2; i++) {
        int v = r1[i + 5];
        if (v != -1) {
            result = v;
            break;
        }
    }
    return Slot_GetPositionPtr(r0, result);
}

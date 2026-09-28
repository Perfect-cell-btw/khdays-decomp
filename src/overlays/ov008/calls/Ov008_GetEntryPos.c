/* Take the first of the two words at +0x14/+0x18 of the record that is not -1 (or -1 if both are),
 * and pass it to Slot_GetPositionPtr with the caller's first argument. */

extern int Slot_GetPositionPtr(int r0, int r1);

int Ov008_GetEntryPos(int r0, int *r1)
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

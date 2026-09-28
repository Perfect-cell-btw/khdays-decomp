/* Query the current block's descriptor; unless its kind halfword reads 1, clear the caller's slot
 * at +0x34. The kind is read UNSIGNED (ldrh). */

extern int Ov008_GetCtxBlock4a80(void *object);
extern void Ov008_GetTouchSample(int arg0, void *out);

void Ov008_ClearSlotUnlessKind1(void *object)
{
    int state[2];

    Ov008_GetTouchSample(Ov008_GetCtxBlock4a80(object), state);

    if (*(unsigned short *)((char *)state + 4) != 1) {
        *(int *)((char *)object + 0x34) = 0;
    }
}

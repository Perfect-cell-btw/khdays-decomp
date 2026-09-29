/* AI step: posts tag 1, starts a timer of 0x78 frames plus a random offset and installs the next
 * movement step. */

extern void Ov107_PostTagUpdate(int obj, int tag1, int tag_lsb);
extern int RandNextScaled(unsigned int mul);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov167_HoverBobTick(void);

void Ov167_AiStep_StartTag1WithTimer(char *obj) {
    char *p = *(char **)(obj + 4);
    Ov107_PostTagUpdate(*(int *)p, 1, 1);
    *(int *)(p + 0x54) = RandNextScaled(1) + 0x78;
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov167_HoverBobTick);
}

/* Plays looping anim 1, rolls the bob time and installs the hover bob tick. */

extern void Ov107_PostTagUpdate(int obj, int tag1, int tag_lsb);
extern int RandNextScaled(unsigned int mul);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov178_HoverBobTick(void);

void Ov178_AiEnterHover(char *obj) {
    char *p = *(char **)(obj + 4);
    Ov107_PostTagUpdate(*(int *)p, 1, 1);
    *(int *)(p + 0x54) = RandNextScaled(1) + 0x28;
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov178_HoverBobTick);
}

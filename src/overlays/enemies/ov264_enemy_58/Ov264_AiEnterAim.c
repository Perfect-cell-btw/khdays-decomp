/* Plays looping anim 1, rolls the move timer and installs the aim step. */

extern void Ov107_PostTagUpdate(int obj, int tag1, int tag_lsb);
extern int RandNextScaled(unsigned int mul);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov264_AimSubtractVecSetAngleThenGatedAdvance(void);

void Ov264_AiEnterAim(char *obj) {
    char *p = *(char **)(obj + 4);
    Ov107_PostTagUpdate(*(int *)p, 1, 1);
    int min = *(int *)(*(char **)p + 0x224);
    int range = *(int *)(*(char **)p + 0x228) - min;
    if (range < 0) range = -range;
    *(int *)(p + 0x50) = min + RandNextScaled(range + 1);
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov264_AimSubtractVecSetAngleThenGatedAdvance);
}

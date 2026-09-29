/* Plays anim 4, resets the burst state and installs the burst tick. */

extern void Ov107_PostTagUpdate(int obj, int tag1, int tag_lsb);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov134_BurstAttackTick(void);

void Ov134_AiEnterBurst(char *obj) {
    char *p = *(char **)(obj + 4);
    Ov107_PostTagUpdate(*(int *)p, 4, 0);
    p[0x40] = 0;
    *(int *)(p + 0x30) = 0;
    p[0x41] = 0;
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov134_BurstAttackTick);
}

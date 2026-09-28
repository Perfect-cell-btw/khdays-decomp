/* Plays anim 15, resets the combo state and installs the combo tick. */

extern void Ov107_PostTagUpdate(int obj, int tag1, int tag_lsb);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov269_ComboTick(void);

void Ov269_AiEnterCombo(char *obj) {
    char *p = *(char **)(obj + 4);
    Ov107_PostTagUpdate(*(int *)p, 15, 0);
    p[0x50] = 0;
    *(int *)(p + 0x30) = 0;
    p[0x53] = 0;
    *(int *)(p + 0x54) = 0;
    p[0x51] = 0;
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov269_ComboTick);
}

/* Same shape as ov202/ov203 020cd4a0: the 0x44 gate byte is read UNSIGNED (ldrb)
 * while the 0x20 selector stays SIGNED (ldrsb). The two byte reads in this function
 * have opposite signedness. */
extern void Ov107_PostTagUpdate(int obj, int tag1, int tag_lsb);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov203_CloseOnTarget(void);
void Ov203_AiLoopAnim2OnFlagClear(char *obj) {
    char *p = *(char **)(obj + 0x4);
    if (**(unsigned char **)(p + 0x44) != 0) return;
    Ov107_PostTagUpdate(*(int *)(p + 0x0), 2, 1);
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov203_CloseOnTarget);
}

/* Invokes slot 0x74 on the part objects, then the base handler. */

extern void Ov107_InvokeSlot0x74(void *b, int v);
extern void Ov107_Actor_DetachFromRegion(void *a, void *b);

void Ov193_NotifyPartsThenBase(char *a, void *b) {
    int i;
    for (i = 0; i < 4; i++) {
        int *base = *(int **)(a + 0x3a4);
        Ov107_InvokeSlot0x74(b, base[i]);
    }
    Ov107_Actor_DetachFromRegion(a, b);
}

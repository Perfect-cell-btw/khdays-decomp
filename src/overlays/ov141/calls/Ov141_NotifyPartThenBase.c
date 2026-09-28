extern void Ov107_InvokeSlot0x74(void *a, int v);
extern void Ov107_Actor_DetachFromRegion(void *a, void *b);

void Ov141_NotifyPartThenBase(char *a, void *b) {
    Ov107_InvokeSlot0x74(b, *(int *)(a + 0x3c8));
    Ov107_Actor_DetachFromRegion(a, b);
}

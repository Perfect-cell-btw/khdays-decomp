extern void SetIndexedSlot();
extern void Ov107_PostTagUpdate();
extern void Ov215_StepBounceOffContact(void);
void Ov215_stActivateWhenReady(int node) {
    int *s = *(int **)(node + 4);
    if (*(unsigned char *)(s[1] + 0xad) != 0) return;
    Ov107_PostTagUpdate(*s, 7, 1);
    SetIndexedSlot(node, *(signed char *)(node + 0x20), Ov215_StepBounceOffContact);
}

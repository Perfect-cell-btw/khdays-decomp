/* ov node state callback: returns until the bound subitem's ready byte [+0xad]==0, then requests a
 * pose via ov107 and advances the node state slot. */

extern void SetIndexedSlot();
extern void Ov107_PostTagUpdate();
extern void Ov216_StepBounceOffContact(void);
void Ov216_stActivateWhenReady(int node) {
    int *s = *(int **)(node + 4);
    if (*(unsigned char *)(s[1] + 0xad) != 0) return;
    Ov107_PostTagUpdate(*s, 7, 1);
    SetIndexedSlot(node, *(signed char *)(node + 0x20), Ov216_StepBounceOffContact);
}

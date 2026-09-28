/* Kick anim 0xc, retract via 020cc830, reset fields, set +0x5c=0xc00, then dispatch. */
extern int Ov107_PostTagUpdate(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov283_MapHeldItemKindToAnim(int, int);
extern int Ov283_VolleyTick(int);
void Ov283_AiEnterVolley(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate(*(int *)owner, 0xc, 0);
    Ov283_MapHeldItemKindToAnim(*(int *)owner, 2);
    *(int *)(owner + 0x68) = 0;
    *(int *)(owner + 0x6c) = 0;
    *(int *)(owner + 0x48) = 0;
    *(int *)(owner + 0x74) = 0;
    *(int *)(owner + 0x5c) = 0xc00;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov283_VolleyTick);
}

/* If the linked partner (+0x5ac -> +0x18c) is present, cache it into +0xc and when non-null fire
 * its 0x15e/0xd effect and notify Ov267_SetMode70; always kick anim 8, clear +0x50 and dispatch. */
extern int Ov022_ToggleBit13ByMode(int, int);
extern int Ov107_BuildAndSendUpdate(int, int, int, int);
extern int Ov267_SetMode70(int, int);
extern int Ov107_PostTagUpdate(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov267_CarryTick(int);
void Ov267_AiGrabTarget(int param_1) {
    int owner = *(int *)(param_1 + 4);
    int t = *(int *)(*(int *)owner + 0x5ac);
    if (t != 0) {
        int v = *(int *)(t + 0x18c);
        *(int *)(owner + 0xc) = v;
        if (v != 0) {
            Ov022_ToggleBit13ByMode(v, 1);
            Ov107_BuildAndSendUpdate(*(int *)owner, 0x15e, 0xd, *(int *)(owner + 8));
            Ov267_SetMode70(owner, 1);
        }
    }
    Ov107_PostTagUpdate(*(int *)owner, 8, 0);
    *(int *)(owner + 0x50) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov267_CarryTick);
}

/* Refreshes the child selector at +0x3fc, then runs the object tick. */

extern int Ov107_RefreshAndSelectChild();
extern int Ov107_ProcessObjectTick();

int Ov222_TickWithChildRefresh(int *r0, int r1) {
    Ov107_RefreshAndSelectChild(r0[0xff]);
    return Ov107_ProcessObjectTick(r0, r1);
}

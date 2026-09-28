extern int Ov107_RefreshAndSelectChild();
extern int Ov107_ProcessObjectTick();

int Ov122_ReleaseAndDestroy(int *r0, int r1) {
    Ov107_RefreshAndSelectChild(r0[0xe8]);
    return Ov107_ProcessObjectTick(r0, r1);
}

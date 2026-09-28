extern int Ov107_RefreshAndSelectChild();
extern int Ov107_ProcessObjectTick();

int Ov164_TickWithChildRefresh(int *r0, int r1)
{
    Ov107_RefreshAndSelectChild(r0[0xf2]);
    return Ov107_ProcessObjectTick(r0, r1);
}

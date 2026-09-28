extern int SetSubitemState();
extern int RefreshObjectCallbacks();

void Ov196_Model_SetTrack0(int *r0, int a1, int a2)
{
    SetSubitemState(r0[0x384 / 4], 0, (short)a1, a2);
    RefreshObjectCallbacks(r0[0x384 / 4], 0);
}

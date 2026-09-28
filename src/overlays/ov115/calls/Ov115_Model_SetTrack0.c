/* SetSubitemState on track 0 of the actor model (+0x384) with the given blend and value, then
 * RefreshObjectCallbacks. */

extern int SetSubitemState();
extern int RefreshObjectCallbacks();

void Ov115_Model_SetTrack0(int *r0, int a1, int a2)
{
    SetSubitemState(r0[0x384 / 4], 0, (short)a1, a2);
    RefreshObjectCallbacks(r0[0x384 / 4], 0);
}

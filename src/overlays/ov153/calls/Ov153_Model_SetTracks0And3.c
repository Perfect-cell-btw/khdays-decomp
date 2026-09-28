/* SetSubitemState on model tracks 0 and 3 with the given blend and value, then
 * RefreshObjectCallbacks. */

extern int SetSubitemState(void *, int, short, int);
extern int RefreshObjectCallbacks();

int Ov153_Model_SetTracks0And3(int *r0, int r1, int r2) {
    SetSubitemState((void *)r0[0xe1], 0, r1, r2);
    SetSubitemState((void *)r0[0xe1], 3, r1, r2);
    return RefreshObjectCallbacks(r0[0xe1], 0);
}

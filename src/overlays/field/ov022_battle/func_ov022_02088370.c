/* Returns the current frame of a player's first animation track (0 when it has no actor). */

extern int GetEntryField20ByIndex(int arg0);
extern int Anim_GetFrame(unsigned short *arg0, int arg1);
int func_ov022_02088370(int arg0) {
    int e = GetEntryField20ByIndex(arg0);
    if (e == 0) return 0;
    return Anim_GetFrame((unsigned short *)(*(int *)(e + 0x20) + 4), 0);
}

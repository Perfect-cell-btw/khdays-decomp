/* Set +0x11c to 4 then tail-call the ov043 handler with mode 2. */
extern int Ov043_RebindAnimTracks(int, int);
int Ov043_EnterState4(int param_1, int param_2) {
    *(int *)(param_2 + 0x11c) = 4;
    return Ov043_RebindAnimTracks(param_2, 2);
}

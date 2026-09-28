/* Steps a playing animation record and stops it when it ends. */

extern unsigned short Sequence_UpdateTracks(unsigned short *arg0, int arg1);
void func_ov022_02092808(unsigned char *arg0, int arg1) {
    if ((*arg0 & 1) && (char)arg0[1] != 0 && (char)arg0[1] == 1) {
        if (Sequence_UpdateTracks((unsigned short *)(arg0 + 4), arg1) != 0) arg0[1] = 0;
    }
}

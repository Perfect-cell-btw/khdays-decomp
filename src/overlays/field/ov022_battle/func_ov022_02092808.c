extern int Sequence_UpdateTracks(unsigned short *arg0, int arg1);
void func_ov022_02092808(unsigned char *arg0, int arg1) {
    if ((*arg0 & 1) && (char)arg0[1] != 0 && (char)arg0[1] == 1) {
        if (Sequence_UpdateTracks((unsigned short *)(arg0 + 4), arg1) != 0) arg0[1] = 0;
    }
}

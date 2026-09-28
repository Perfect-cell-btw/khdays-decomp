extern int *GetEntryField20ByIndex(int i);

int Ov017_SetFlagBit62OnFour(void) {
    int i;
    for (i = 0; i < 4; i++) {
        int *p = GetEntryField20ByIndex(i);
        if (p) {
            *(unsigned long long *)p |= 0x4000000000000000ULL;
        }
    }
    return 1;
}

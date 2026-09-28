extern int Slot_Spawn(int a, int b, int c, int d);

typedef struct { unsigned char b0 : 1; } Flags;

int Ov102_PlayHitVoiceIfEnabled(int owner, int node) {
    int obj = *(int *)(owner + 8);
    int *hdr = *(int **)(node + 0x138);
    int loud = 0;
    *(signed char *)(node + 2) = 4;
    *(int *)(node + 4) = 0x3000;
    if (*hdr & 0x200) loud = 1;
    if (((Flags *)(obj + 0x694))->b0) {
        Slot_Spawn(0xd4, loud, node + 0xcc, 0);
    }
    return 0;
}

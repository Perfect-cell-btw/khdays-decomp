struct Ov022SpawnRecord {
    int x;
    int y;
    int z;
};

struct Ov022DispatchFlags {
    unsigned char mode : 2;
    unsigned char rest : 6;
};

extern void Ov022_AvoidAnimationSlots(int context, struct Ov022SpawnRecord *record,
                                int value, struct Ov022SpawnRecord *output);
extern int Ov022_ClaimPoolSlot(int context, struct Ov022SpawnRecord *record);

int Ov022_DispatchSpawnRecord(int context, const struct Ov022SpawnRecord *record,
                        short value) {
    unsigned char *dispatch = *(unsigned char **)(context + 0x20);
    struct Ov022SpawnRecord copy;
    int slot;

    copy = *record;
    if ((((struct Ov022DispatchFlags *)dispatch)->mode & 2) != 0) {
        Ov022_AvoidAnimationSlots(context, &copy, *(int *)(dispatch + 0x1c), &copy);
    }
    slot = Ov022_ClaimPoolSlot(context, &copy);
    if (slot != -1) {
        int entry = slot * 0x114 + *(int *)(dispatch + 0xc);
        *(short *)(entry + 0x80) = value;
        *(unsigned short *)(entry + 4) =
            *(unsigned short *)(entry + 4) | 0x20;
    }
    return slot;
}

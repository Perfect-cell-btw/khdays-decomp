/* Binds the model's five animation tracks from the table to the binding and rewinds them. */

extern void BindAnimTrack(int anim, unsigned short slot, int block, short binding);
extern int *Anim_SetFrameWrapped(unsigned short *anim, unsigned int slot, int frame);

struct Ov022TrackTable5 {
    unsigned int values[5];
};

extern struct Ov022TrackTable5 data_ov022_020b236c;

void Ov022_BindAnimationTracks(unsigned short *anim, int bindingIndex) {
    struct Ov022TrackTable5 table = data_ov022_020b236c;
    int i = 0;

    do {
        unsigned int raw = table.values[i];
        if (0 < (short)anim[(unsigned short)raw + 0x70]) {
            BindAnimTrack((int)anim, raw, (int)(anim + 0x70),
                          (short)bindingIndex);
            Anim_SetFrameWrapped(anim, raw & 0xffff, 0);
        }
        i = i + 1;
    } while (i < 5);
}

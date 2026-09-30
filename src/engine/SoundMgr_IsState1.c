/* Whether the sound manager state (+0xb46fc) is 1. */

typedef struct {
    char pad[0xb46fc];
    unsigned char field_b46fc;
} S_020335a4;

extern S_020335a4 *gSoundMgr;

int SoundMgr_IsState1(void) {
    return gSoundMgr->field_b46fc == 1;
}

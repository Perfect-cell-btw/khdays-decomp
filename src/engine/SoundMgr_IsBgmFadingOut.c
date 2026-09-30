/* Whether the BGM is fading out before a switch (sound manager phase +0xb46fc == 4). */

extern int gSoundMgr;

int SoundMgr_IsBgmFadingOut(void) {
    return *(unsigned char *)(*(int *)&gSoundMgr + 0xb46fc) == 4;
}

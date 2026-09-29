/* Whether the BGM is fading out before a switch (sound manager phase +0xb46fc == 4). */

extern int data_0204c234;

int SoundMgr_IsBgmFadingOut(void) {
    return *(unsigned char *)(*(int *)&data_0204c234 + 0xb46fc) == 4;
}

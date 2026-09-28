/* Unless busy, kick anim 0x19, clear +0x5c/+0x60, then dispatch via c634. */
extern int Ov107_PostTagUpdate(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov227_SpawnTick(int);
void Ov227_AiAnim24To25(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (*(unsigned char *)(*(int *)(owner + 4) + 0xad) != 0) return;
    Ov107_PostTagUpdate(*(int *)owner, 0x19, 0);
    *(int *)(owner + 0x5c) = 0;
    *(int *)(owner + 0x60) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov227_SpawnTick);
}

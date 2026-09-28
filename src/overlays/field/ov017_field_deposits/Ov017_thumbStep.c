extern void Actor_SetVecAndSyncChild(int a, int b);
void Ov017_thumbStep(int p, int b, int c) {
    Actor_SetVecAndSyncChild(p + 0x28, b);
    *(short *)(p + 0x18) = (short)c;
}

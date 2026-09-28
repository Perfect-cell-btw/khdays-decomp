extern int GameState_IsFlagSet(int i);
extern void Ov002_SetRootField85ac(int a, int count);

int Ov069_CountActiveAndCompare(unsigned int arg) {
    int count = 0;
    int i;
    for (i = 9; i < 0x409; i++) {
        if (GameState_IsFlagSet(i)) count++;
    }
    Ov002_SetRootField85ac(1, count);
    if ((unsigned int)count < arg) return 0;
    return 1;
}

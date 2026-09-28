/* Resets the timer of every other prize box of the pool. */

extern int data_ov021_02080f40;
extern int Ov002_MulTagAtField4ePlusField54();

void Ov021_ResetChildrenScoreExceptSelf(int this_) {
    int i;
    if (data_ov021_02080f40 == 0) return;
    for (i = 0; i < (int)*(unsigned short *)(data_ov021_02080f40 + 0x50); i++) {
        int r = Ov002_MulTagAtField4ePlusField54(data_ov021_02080f40, i);
        if (r != this_) {
            *(int *)(r + 0x2b8) = 0x12c000;
        }
    }
}

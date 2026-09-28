/* Special-attack request handler: resets the attack block, sends the matching animation command and
 * returns the approach step (0x21, also clearing the slot ids) or the pursuit step (0x22). */

extern void Ov022_FillEightHalvesMinus1At0x2bd4(int self);
extern void Ov080_ApproachStep(void);
extern void Ov080_PursuitStep(void);

void *Ov080_SelectRequestHandler2(int self, int a) {
    int *blk = (int *)(self + 0x84 + 0x2c00);
    void *cb = 0;
    switch (a) {
    default:
        break;
    case 0x21:
        *(int *)((char *)blk + 0x660) = 0;
        (*(void (**)(int, int))(self + 0x664))(self, 0x2f);
        *(short *)(self + 0x64) = 0x2000;
        Ov022_FillEightHalvesMinus1At0x2bd4(self);
        cb = (void *)&Ov080_ApproachStep;
        break;
    case 0x22:
        *(int *)((char *)blk + 0x660) = 0;
        (*(void (**)(int, int))(self + 0x664))(self, 0x30);
        cb = (void *)&Ov080_PursuitStep;
        break;
    }
    return cb;
}

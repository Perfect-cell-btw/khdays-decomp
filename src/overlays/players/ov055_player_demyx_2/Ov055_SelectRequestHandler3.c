/* Special-attack request handler: for each request kind sets the attack block's phase and variant,
 * sends the matching animation command and returns the step to run (idle or charge). */

extern void Ov055_IdleStep(void);
extern void Ov055_ChargeStep(void);
extern int data_ov055_020b7740;

void *Ov055_SelectRequestHandler3(int self, int req) {
    int *blk = (int *)(*(int *)&data_ov055_020b7740 + 0x194 + 0x2c00);
    void *cb = 0;
    switch (req) {
    default:
        break;
    case 0x21:
        blk[3] = 0;
        blk[4] = 0;
        blk[1] = 0;
        (*(void (**)(int, int))(self + 0x664))(self, 0x2f);
        cb = (void *)&Ov055_IdleStep;
        break;
    case 0x23:
        blk[3] = 2;
        blk[4] = 5;
        (*(void (**)(int, int))(self + 0x664))(self, 0x2f);
        cb = (void *)&Ov055_IdleStep;
        break;
    case 0x22:
        blk[3] = 0;
        blk[2] = 0;
        blk[1] = 0;
        (*(void (**)(int, int))(self + 0x664))(self, 0x30);
        cb = (void *)&Ov055_ChargeStep;
        break;
    }
    return cb;
}

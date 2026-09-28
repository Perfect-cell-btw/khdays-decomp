/* Set up this enemy's three sequence slots (0x10c each from +0x2c5c of the shared object) and its
 * flight parameters: the flight timer at +0x2c58 and +0x2d74 are zeroed, the speed at +0x2d70 set
 * to 0xccd (scaled by 1.5 in hard mode), the three slots register their effect sequences with
 * priority id+7, and the enemy's own emitter at +0x2648 is opened with the 5-word block. */
typedef unsigned char u8;

typedef struct { int w[5]; } Params;

extern int func_02023c40(void);                                                /* game mode: 1 = hard */
extern void RegisterSeqAndInit(int a, void *b, int c, int d);                        /* RegisterSeqAndInit */
extern void Ov022_AllocateSlotWithClass(int a, int b, int c, void *d);
extern char *data_ov096_020bc0c0;
extern char data_ov096_020bc074[];
extern char data_ov096_020bc088[];
extern char data_ov096_020bc09c[];
extern Params data_ov096_020bbfe4;

void Ov096_SetupSequenceSlots(char *self)
{
    Params p;
    char *base = data_ov096_020bc0c0;
    char *rig = base + 0x2c50;

    *(int *)(rig + 8) = 0;
    *(int *)(rig + 0x124) = 0;
    *(int *)(rig + 0x120) = 0xccd;
    if (func_02023c40() == 1) {
        *(int *)(rig + 0x120) = (int)(((long long)*(int *)(rig + 0x120) * 0x1800 + 0x800) >> 12);
    }
    RegisterSeqAndInit((int)(rig + 0xc), data_ov096_020bc074, 1, *(u8 *)(base + 9) + 7);
    RegisterSeqAndInit((int)(rig + 0x128), data_ov096_020bc088, 1, *(u8 *)(base + 9) + 7);
    RegisterSeqAndInit((int)(rig + 0x238), data_ov096_020bc09c, 1, *(u8 *)(base + 9) + 7);
    p = data_ov096_020bbfe4;
    Ov022_AllocateSlotWithClass((int)(self + 0x248 + 0x2400), *(u8 *)(self + 9), 5, &p);
}

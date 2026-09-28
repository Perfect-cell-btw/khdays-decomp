/* Begins the special attack: for the local player sets bit 16 of the two 64-bit flag words, picks
 * the effect speed and range for the game mode and switches to state 0x21. */

extern int Session_GetLocalPlayerIndex(void);
extern int func_02023c40(void);
extern int Ov022_ActorSetState(int *self, int state);
extern int data_ov090_020bcc00;

int Ov090_SetTimingsAndEnterState21(int *self) {
    int *blk = (int *)(*(int *)&data_ov090_020bcc00 + 0xe4 + 0x2c00);
    if (Session_GetLocalPlayerIndex() == 0) {
        *(long long *)((char *)self + 0x464) |= 0x10000;
    }
    if (Session_GetLocalPlayerIndex() == 0) {
        *(long long *)((char *)self + 0x46c) |= 0x10000;
    }
    blk[5] = (func_02023c40() == 1) ? 0x1333 : 0xccd;
    blk[6] = (func_02023c40() == 1) ? 0x600 : 0x400;
    return Ov022_ActorSetState(self, 0x21);
}

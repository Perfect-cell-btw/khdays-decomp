/* Branch on 020cd63c: if active arm the 020c5af8 burst, else reset via 020cd5ec; dispatch accordingly. */
extern int Ov212_IsState6cActive(int, int);
extern int Ov107_BuildAndSendUpdate(int, int, int, int);
extern int Ov212_SetMode70(int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov212_PickRetreatSpot(int);
extern int Ov212_AiRetreatWait(int);
void Ov212_AiEnterRetreatCheck(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (Ov212_IsState6cActive(owner, 1) != 0) {
        Ov107_BuildAndSendUpdate(*(int *)owner, 0x128, 6, *(int *)(owner + 8));
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov212_PickRetreatSpot);
    } else {
        Ov212_SetMode70(owner, 0);
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov212_AiRetreatWait);
    }
}

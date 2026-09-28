/* Poll Ov267_IsState6cActive: on success arm the 0x15e/6 timer and advance to Ov267_PickRetreatSpot, otherwise notify Ov267_SetMode70
 * and advance to Ov267_AiRetreatWait. */
extern int Ov267_IsState6cActive(int, int);
extern int Ov107_BuildAndSendUpdate(int, int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov267_SetMode70(int, int);
extern int Ov267_PickRetreatSpot(int);
extern int Ov267_AiRetreatWait(int);
void Ov267_AiEnterRetreatCheck(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (Ov267_IsState6cActive(owner, 1) != 0) {
        Ov107_BuildAndSendUpdate(*(int *)owner, 0x15e, 6, *(int *)(owner + 8));
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov267_PickRetreatSpot);
    } else {
        Ov267_SetMode70(owner, 0);
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov267_AiRetreatWait);
    }
}

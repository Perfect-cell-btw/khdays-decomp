/* Poll Ov266_IsState6cActive: on success arm the 0x15e/6 timer and advance to Ov266_PickRetreatSpot, otherwise notify Ov266_SetMode70
 * and advance to Ov266_AiRetreatWait. */
extern int Ov266_IsState6cActive(int, int);
extern int Ov107_BuildAndSendUpdate(int, int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov266_SetMode70(int, int);
extern int Ov266_PickRetreatSpot(int);
extern int Ov266_AiRetreatWait(int);
void Ov266_AiEnterRetreatCheck(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (Ov266_IsState6cActive(owner, 1) != 0) {
        Ov107_BuildAndSendUpdate(*(int *)owner, 0x15e, 6, *(int *)(owner + 8));
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov266_PickRetreatSpot);
    } else {
        Ov266_SetMode70(owner, 0);
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov266_AiRetreatWait);
    }
}

extern int Ov002_Hud_IsPanelOpen(void);
extern int Ov002_GetRootField8b68Alt(void);
extern int Ov002_RunShutdownHook(void);
extern int Ov002_SetLeaveRequest(int bOn);
extern int Ov002_RecordElementHit(void *pEntry, void *pReq, int nKind);
extern void func_ov022_020888ec(int nIndex, int bOn);
extern void Ov002_List_SetSlot(int arg0, int arg1);
extern int Ov002_GetPhaseWord(void);
extern int func_ov022_02083f0c(void);
extern int func_ov022_02083f5c(void);
extern void func_ov022_02086818(int nHandle, int nMode);
extern void Ov002_SetOrClearFlag200(int nHandle, int nMode);

/* Try to start a spare entry from a message.
 *
 * Nothing happens if the entry is already past its first phase or if any of the
 * three global guards refuses. The request is built on the stack from the index
 * the message carries and handed to the queue; if the queue takes it the entry
 * moves to phase one and the index is published, and the extra step below only
 * runs in the one mode that asks for it. The result is always zero.
 */
int Ov002_SpareEntryTryBegin(char *pEntry, unsigned char *pMsg)
{
    unsigned char aReq[8];
    int nHandle;

    if (*(unsigned char *)(pEntry + 0x2c) != 0) {
        return 0;
    }

    if (Ov002_Hud_IsPanelOpen() != 0 || Ov002_GetRootField8b68Alt() != 0
        || Ov002_RunShutdownHook() != 0) {
        return 0;
    }

    if (Ov002_SetLeaveRequest(1) != 0) {
        aReq[0] = 1;
        aReq[4] = pMsg[0];

        if (Ov002_RecordElementHit(pEntry, aReq, 6) != 0) {
            *(unsigned char *)(pEntry + 0x2c) = 1;
            func_ov022_020888ec(pMsg[0], 1);
            Ov002_List_SetSlot((int)pEntry, pMsg[0]);

            if (Ov002_GetPhaseWord() == 1) {
                nHandle = func_ov022_02083f0c();
                func_ov022_02086818(func_ov022_02083f5c(), 0);
                Ov002_SetOrClearFlag200(nHandle, 1);
            }
        } else {
            Ov002_SetLeaveRequest(0);
        }
    }

    return 0;
}

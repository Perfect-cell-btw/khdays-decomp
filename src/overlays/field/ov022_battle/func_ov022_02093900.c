/* Raises the actor's ability levels for the abilities it has (15 rows) by the amount; the host
 * flags the actor when any changed. */

extern int Slot_EvalPackedParam(unsigned int a, int b);
extern int Load2DArrayU8(unsigned int a, int b);
extern void ClampAndStoreLevelEntry(unsigned int a, int b, int c);
extern int Session_GetLocalPlayerIndex(void);

void func_ov022_02093900(int param_1, int param_2) {
    int bVar1 = 0;
    int iVar5 = 0;
    do {
        if (Slot_EvalPackedParam(*(unsigned char *)(param_1 + 9), iVar5 + 1) != 0) {
            int iVar4;
            bVar1 = 1;
            iVar4 = Load2DArrayU8(*(unsigned char *)(param_1 + 9), iVar5);
            ClampAndStoreLevelEntry(*(unsigned char *)(param_1 + 9), iVar5, param_2 + iVar4);
        }
        iVar5 = iVar5 + 1;
    } while (iVar5 < 0xf);
    if (Session_GetLocalPlayerIndex() != 0) {
        return;
    }
    if (bVar1 == 0) {
        return;
    }
    *(unsigned long long *)(param_1 + 0x46c) |= 0x20000000000LL;
}

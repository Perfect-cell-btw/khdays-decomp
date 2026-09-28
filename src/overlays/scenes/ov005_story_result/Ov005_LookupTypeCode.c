/* Advance 02030788, then map the current 020315c0 slot to a priority table, storing its index. */
extern void Session_GetLocalPlayerIndex(int a);
extern int Slot4_GetIfOccupied(void);
extern int data_ov005_0205b2e4;
int Ov005_LookupTypeCode(int param_1) {
    int r = 0xa;
    Session_GetLocalPlayerIndex(param_1);
    int x = Slot4_GetIfOccupied();
    if (x != 0) r = (&data_ov005_0205b2e4)[*(int *)(x + 4)];
    if (param_1 != 0) *(int *)param_1 = *(int *)(x + 4);
    return r;
}

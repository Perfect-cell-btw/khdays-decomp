/* Refresh +0x390 via 020cab14; unless it and the linked node's +0x4c4 are live, just latch
 * sub-state 2, otherwise kick anim 2, clear +0x30/+0x3d and advance to 020d013c. */
extern int Ov107_FindNearestObject(int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov107_PostTagUpdate(int, int, int);
extern int Ov245_ChargeTick(int);
void Ov245_Carrier_AiEnterCharge(int param_1) {
    int owner = *(int *)(param_1 + 4);
    *(int *)(*(int *)owner + 0x390) = Ov107_FindNearestObject(*(int *)owner, 0);
    if (*(int *)(*(int *)owner + 0x390) == 0 ||
        *(int *)(*(int *)(*(int *)owner + 0x3dc) + 0x4c4) == 0) {
        *(unsigned char *)(*(int *)owner + 0x1c7) = 2;
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
    } else {
        Ov107_PostTagUpdate(*(int *)owner, 2, 0);
        *(int *)(owner + 0x30) = 0;
        *(unsigned char *)(owner + 0x3d) = 0;
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov245_ChargeTick);
    }
}

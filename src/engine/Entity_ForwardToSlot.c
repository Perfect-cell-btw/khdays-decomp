/* Index the entity array of the manager singleton (data_0204c208, array at +0xc4, stride 0x184) by
 * slot and forward the remaining four arguments to Actor_ArmWithMessage. */

extern void Actor_ArmWithMessage(int, int, int, int, int);
extern int data_0204c208;

void Entity_ForwardToSlot(int param_1, int param_2, int param_3, void *pArg4, int param_5) {
    int param_4 = (int)pArg4;
    Actor_ArmWithMessage(data_0204c208 + 0xc4 + param_1 * 0x184, param_2, param_3, param_4, param_5);
}

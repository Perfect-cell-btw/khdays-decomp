/* THUMB tail-forward to Entity_Register with the 0x184-stride track entry at
 * (*data_0204c208)+0xc4+index*0x184, passing args 2-4 through. */

extern void Entity_Register(int, int, int, int);
extern int data_0204c208;
void TailForwardTrackEntry(int param_1, void *pArg2, int param_3, int param_4) {
    int param_2 = (int)pArg2;
    Entity_Register(data_0204c208 + 0xc4 + param_1 * 0x184, param_2, param_3, param_4);
}

/* THUMB tail-forward to Actor_StartMotion with the 0x184-stride track entry at
 * (*data_0204c208)+0xc4+index*0x184, passing args 2-4 through. */

extern void Actor_StartMotion(int, int, int, int);
extern int data_0204c208;
void TailForwardTrackEntry_2(int param_1, int param_2, int param_3, int param_4) {
    Actor_StartMotion(data_0204c208 + 0xc4 + param_1 * 0x184, param_2, param_3, param_4);
}

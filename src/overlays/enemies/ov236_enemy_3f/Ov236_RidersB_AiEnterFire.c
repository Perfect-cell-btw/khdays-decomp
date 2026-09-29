/* Clear the +0x78/+0x7c fields, play the anim (ov107 mode 0xa) and register the handler. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov236_RiderFireTickB(int);
void Ov236_RidersB_AiEnterFire(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(int *)(child + 0x78) = 0;
    *(signed char *)(child + 0x7c) = 0;
    Ov107_PostTagUpdate(*(int *)child, 0xa, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov236_RiderFireTickB);
}

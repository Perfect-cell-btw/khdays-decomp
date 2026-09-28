/* Tail-call SetWordAt0x588To1 with the global at data_ov106_020b8b60. */
extern int SetWordAt0x588To1(int arg);
extern int data_ov106_020b8b60;
int Ov106_ArmObject(void) {
    return SetWordAt0x588To1(*(int *)&data_ov106_020b8b60);
}

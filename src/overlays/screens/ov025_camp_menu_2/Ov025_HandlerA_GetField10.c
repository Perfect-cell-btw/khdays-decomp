/* Follow the +0x10 link of the stride-8 table entry indexed by the first ov025 counter. */

extern int data_ov025_020b574c;
extern int data_ov025_020b4ab0;

int Ov025_HandlerA_GetField10(void) {
    return *(int *)(*(int *)((char *)&data_ov025_020b4ab0 + *(int *)&data_ov025_020b574c * 8) + 0x10);
}

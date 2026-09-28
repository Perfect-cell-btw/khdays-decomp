/* Follow the +0x10 link of the stride-8 table entry indexed by the first ov009 counter. */
struct e8 { int a, b; };
extern int data_ov009_020563ec;
extern int data_ov009_020562dc;
int Ov009_HandlerA_GetField10(void) {
    int idx = data_ov009_020563ec;
    return *(int *)(((struct e8 *)&data_ov009_020562dc)[idx].a + 0x10);
}

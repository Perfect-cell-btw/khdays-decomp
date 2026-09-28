/* Polls the page input and runs the two current handlers. */

extern void Ov025_PollPageInput();
extern void Ov025_HandlerA_Call2();
extern void Ov025_HandlerB_Call2();
extern int data_ov025_020b5744;

void Ov025_InitThenDispatchTwoHandlers(void) {
    Ov025_PollPageInput();
    Ov025_HandlerA_Call2(*(int *)(((int *)&data_ov025_020b5744)[1] + 0x959c));
    Ov025_HandlerB_Call2(*(int *)(((int *)&data_ov025_020b5744)[1] + 0x95a0));
}

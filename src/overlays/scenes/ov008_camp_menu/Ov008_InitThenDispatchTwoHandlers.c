/* Polls the page input, then runs the two page handlers. */

extern char *data_ov008_02090f04[];
extern void Ov008_PollPageInput(void);
extern void Ov008_HandlerA_Call2(int arg0);
extern void Ov008_HandlerB_Call2(int arg0);

void Ov008_InitThenDispatchTwoHandlers(void)
{
    Ov008_PollPageInput();
    Ov008_HandlerA_Call2(*(int *)(data_ov008_02090f04[1] + 0x959c));
    Ov008_HandlerB_Call2(*(int *)(data_ov008_02090f04[1] + 0x95a0));
}

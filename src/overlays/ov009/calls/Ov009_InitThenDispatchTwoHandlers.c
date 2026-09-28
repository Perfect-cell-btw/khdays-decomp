extern char *data_ov009_020563e4[];
extern void Ov009_PollPageInput(void);
extern void Ov009_HandlerA_Call2(int arg0);
extern void Ov009_HandlerB_Call2(int arg0);

void Ov009_InitThenDispatchTwoHandlers(void)
{
    Ov009_PollPageInput();
    Ov009_HandlerA_Call2(*(int *)(data_ov009_020563e4[1] + 0x959c));
    Ov009_HandlerB_Call2(*(int *)(data_ov009_020563e4[1] + 0x95a0));
}

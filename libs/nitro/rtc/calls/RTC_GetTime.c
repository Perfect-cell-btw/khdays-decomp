extern int RTC_GetTimeAsync(int a, void *b, int c);
extern void StoreGlobalIntAt2c(void);
extern void RtcWaitBusy(void);
extern int data_02046438[];

int RTC_GetTime(int param_1) {
    int r = RTC_GetTimeAsync(param_1, StoreGlobalIntAt2c, 0);
    data_02046438[0xb] = r;
    if (r == 0) RtcWaitBusy();
    return data_02046438[0xb];
}

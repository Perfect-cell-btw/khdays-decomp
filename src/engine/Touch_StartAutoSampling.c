/* Starts touch auto-sampling into the 5-entry ring (4 per frame), waits and returns whether it
 * succeeded. */

extern int data_0204c1c4;
extern void TP_RequestAutoSamplingStartAsync(int arg0, int arg1, void *ptr, int arg3);
extern void TP_WaitBusy(int arg0);
extern int TP_CheckError(int arg0);

int Touch_StartAutoSampling(void) {
    TP_RequestAutoSamplingStartAsync(0, 4, &data_0204c1c4, 5);
    TP_WaitBusy(2);
    return TP_CheckError(2) == 0;
}

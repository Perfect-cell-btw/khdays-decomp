/* Shut down: run cleanup 0204d358(1), terminate, return 0. */
extern void Ov000_SetupBootTextScreen(int);
extern void OS_Terminate(void);
int Ov000_ShowErrorAndHalt(void) {
    Ov000_SetupBootTextScreen(1);
    OS_Terminate();
    return 0;
}

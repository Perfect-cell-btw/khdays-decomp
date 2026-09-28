/* Ov024_RunDisplayTeardownSteps -- conditionally run the two ov024 teardown steps, ov024. */
extern void Ov024_MobiClip_SetUpMainEngine(void);
extern void Ov024_MobiClip_SetUpSubEngine(void);
void Ov024_RunDisplayTeardownSteps(int doA, int doB) {
    if (doA != 0) {
        Ov024_MobiClip_SetUpMainEngine();
    }
    if (doB != 0) {
        Ov024_MobiClip_SetUpSubEngine();
    }
}

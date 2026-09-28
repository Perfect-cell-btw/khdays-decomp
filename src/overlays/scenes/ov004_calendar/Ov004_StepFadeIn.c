typedef struct Ov004Context {
    char pad_0000[0xafc];
    int phaseFrame;
} Ov004Context;

extern Ov004Context *data_ov004_02051384;
extern void Ov004_SetPlaneBrightness(int frame, int mode);

void Ov004_StepFadeIn(void) {
    data_ov004_02051384->phaseFrame++;
    if (data_ov004_02051384->phaseFrame > 0x19) {
        return;
    }
    Ov004_SetPlaneBrightness(data_ov004_02051384->phaseFrame - 0x10, 3);
}

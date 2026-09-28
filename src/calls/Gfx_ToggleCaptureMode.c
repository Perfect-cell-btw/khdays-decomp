extern void Gfx_SetupBlendCapture(void *ptr);
extern void Gfx_SetupSubScreenCapture(void *ptr);
extern unsigned char data_0204c214[];

int Gfx_ToggleCaptureMode(void *ptr) {
    if (data_0204c214[1] != 0) {
        unsigned char value;

        if (data_0204c214[0] != 0) {
            Gfx_SetupBlendCapture(ptr);
        } else {
            Gfx_SetupSubScreenCapture(ptr);
        }

        data_0204c214[1] = 0;
        value = data_0204c214[0];
        data_0204c214[0] = value == 0;
    }

    return data_0204c214[0];
}

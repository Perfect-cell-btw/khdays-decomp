/* Character constructor: builds the panel object and, outside the restricted mode, loads the
 * character's archive file and binds it to its resource slot, resetting the animation state; then
 * initialises the effect state and requests the two voice ids; returns the decoder step. */

extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov044_InitPanelObject(int *ctx);
extern int Archive_LoadFile(void *tbl, int n);
extern void Resource_BindFileToSlot(int a, int b, int c, int d);
extern void Ov044_initStateSlotsDispatch(int a, int b);
extern void Ov022_RequestVoiceIds(int a, int b, int c);
extern void Ov022_ArmDecoder(void);
extern unsigned char data_0204c240;
extern int gOv044XionEtcPackPath;

void *Ov044_InitSubsystemAndReturnTick(int *ctx) {
    int base = NNSi_FndGetCurrentRootHeap();
    Ov044_InitPanelObject(ctx);
    if ((data_0204c240 & 4) == 0) {
        *(int *)(base + 0x2c50) = Archive_LoadFile(&gOv044XionEtcPackPath, ctx[0] + 7);
        Resource_BindFileToSlot(base + 0x2c2c, *(int *)(base + 0x20) + 4,
                      *(int *)(base + 0x2c50), ctx[0] + 7);
        *(int *)(base + 0x6bc) = -1;
        (*(void (**)(int, int))(base + 0x664))(base, 0);
    }
    Ov044_initStateSlotsDispatch(base, base + 0x2ca8);
    Ov022_RequestVoiceIds(base, 0x50, 0xd1);
    return (void *)&Ov022_ArmDecoder;
}

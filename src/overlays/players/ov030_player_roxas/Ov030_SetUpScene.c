/* Sets the ov030 scene up and hands back its per-frame entry point.
 *
 * Clears the two slots the scene fills in later, parks the slew threshold at
 * its minimum and runs the shared init. Outside mission mode it also loads the
 * archive entry for this scene, wires it up, resets the focus field and calls
 * the scene's own hook; and unless story flag 0x2089 is set it instantiates the
 * extra class from a template whose last word is biased by the scene id.
 */
struct Ov030ClassArgs { int w00, w04, w08, w0c, w10; };

extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov030_CreateActor(int *self);
extern void *Archive_LoadFile(void *archive, int entry);
extern void Resource_BindFileToSlot(int a, int b, int c, int d);
extern int GameState_IsFlagSet(int flag);
extern int InstantiateClass(void *descriptor, struct Ov030ClassArgs *args);
extern void Ov030_initStateSlotsDispatch(int base, int slots);
extern void Ov022_RequestVoiceIds(int base, int a, int b);
extern void Ov022_ArmDecoder(void);
extern unsigned char data_0204c240;
extern int gOv030RoxasEtcPackPath;
extern struct Ov030ClassArgs data_ov030_020b58b0;
extern int data_ov022_020b2930;

void *Ov030_SetUpScene(int *self) {
    int base = NNSi_FndGetCurrentRootHeap();

    *(int *)(base + 0x2c50) = 0;
    *(int *)(base + 0x2cac) = 0;
    *(int *)(base + 0x2ca8) = (int)0x80000000;

    Ov030_CreateActor(self);

    if ((data_0204c240 & 4) == 0) {
        *(int *)(base + 0x2c50) =
            (int)Archive_LoadFile(&gOv030RoxasEtcPackPath, *self + 7);
        Resource_BindFileToSlot(base + 0x2c2c, *(int *)(base + 0x20) + 4,
                      *(int *)(base + 0x2c50), *self + 7);
        *(int *)(base + 0x6bc) = -1;
        (*(void (**)(int, int))(base + 0x664))(base, 0);
        *(int *)(base + 0x2cac) = 0;
        if (GameState_IsFlagSet(0x2089) == 0) {
            struct Ov030ClassArgs args = data_ov030_020b58b0;

            args.w10 += *self;
            *(int *)(base + 0x2cac) =
                InstantiateClass(&data_ov022_020b2930, &args);
        }
    }

    Ov030_initStateSlotsDispatch(base, base + 0x2cb0);
    Ov022_RequestVoiceIds(base, 0x41, 0xd0);
    return (void *)&Ov022_ArmDecoder;
}

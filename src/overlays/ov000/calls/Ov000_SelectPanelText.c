typedef unsigned char  u8;

typedef struct Ov000SubSceneContext {
    u8 pad_0000[0x20];
    int baseMode;
    u8 pad_0024[0x4b58];
    u8 textSurface[0x3c];
    u8 variantSource[0x0c];
} Ov000SubSceneContext;

extern Ov000SubSceneContext *volatile data_ov000_0205ac28;
extern void Obj_InvokeInnerVtable4(void *surface);
extern int *Ov000_GetVarRecordByIndex(void *object, int index);
extern void Ov000_DrawShadowedString(
    void *surface,
    int x,
    int y,
    int depth,
    const int *text
);
extern void Ov000_DrawWithShadow_2(
    void *surface,
    int x,
    int y,
    int depth,
    const int *text,
    int shadowOffset
);
extern void EnqueueObjGfxCommand(void *surface);

void Ov000_SelectPanelText(int mode) {
    Ov000SubSceneContext *context = data_ov000_0205ac28;
    u8 *surfaceBase = (u8 *)context + 0x37c;
    int *text = 0;

    Obj_InvokeInnerVtable4(surfaceBase + 0x4800);

    switch (mode) {
    case 2:
    {
        Ov000SubSceneContext *modeContext = data_ov000_0205ac28;

        switch (modeContext->baseMode) {
        case 0:
            text = Ov000_GetVarRecordByIndex(
                modeContext->variantSource, 5);
            break;
        case 1:
            text = Ov000_GetVarRecordByIndex(
                modeContext->variantSource, 6);
            break;
        case 2:
            text = Ov000_GetVarRecordByIndex(
                modeContext->variantSource, 7);
            break;
        }

        Ov000_DrawShadowedString(
            surfaceBase + 0x4800, 0, -1, 2, text);
        text = Ov000_GetVarRecordByIndex(
            data_ov000_0205ac28->variantSource, 8);
        Ov000_DrawShadowedString(
            surfaceBase + 0x4800, 0, 0x17, 4, text);
        break;
    }
    case 3:
        text = Ov000_GetVarRecordByIndex(
            data_ov000_0205ac28->variantSource, 10);
        Ov000_DrawWithShadow_2(
            surfaceBase + 0x4800, 0, 4, 2, text, 0);
        text = Ov000_GetVarRecordByIndex(
            data_ov000_0205ac28->variantSource, 11);
        Ov000_DrawWithShadow_2(
            surfaceBase + 0x4800, 0x46, 0x19, 2, text, 2);
        text = Ov000_GetVarRecordByIndex(
            data_ov000_0205ac28->variantSource, 12);
        Ov000_DrawWithShadow_2(
            surfaceBase + 0x4800, 0xaa, 0x19, 2, text, 2);
        break;
    }

    EnqueueObjGfxCommand(surfaceBase + 0x4800);
}

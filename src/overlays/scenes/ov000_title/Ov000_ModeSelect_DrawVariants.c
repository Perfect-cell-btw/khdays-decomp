/* Draws the mode select variants: the three options (the selected one indented) or the chosen
 * variant under its heading, then uploads the text. */

typedef unsigned char u8;

typedef struct {
    u8 pad_0000[0x20];
    int selectedVariant;
    u8 pad_0024[0x4b1c];
    u8 drawTarget[0x78];
    u8 variantSource[0x14];
} Ov000SubSceneContext;

extern Ov000SubSceneContext *data_ov000_0205ac28;

extern void Obj_InvokeInnerVtable4(void *object);
extern void *Ov000_GetVarRecordByIndex(void *source, unsigned int index);
extern void Ov000_DrawWithShadow_2(void *object, int x, int y, int mode,
                                void *record, int palette);
extern void EnqueueObjGfxCommand(void *object);

void Ov000_ModeSelect_DrawVariants(int displayMode) {
    void *object = data_ov000_0205ac28->drawTarget;

    Obj_InvokeInnerVtable4(object);

    switch (displayMode) {
    case 2: {
        u8 i;
        int xOffset;
        int zero;

        zero = 0;
        for (i = 0; i < 3; i++) {
            void *record;

            xOffset =
                i == data_ov000_0205ac28->selectedVariant ? 8 : 0;
            record = Ov000_GetVarRecordByIndex(
                data_ov000_0205ac28->variantSource, i + 2);
            Ov000_DrawWithShadow_2(
                data_ov000_0205ac28->drawTarget,
                (u8)xOffset + 0x20, i * 0x10 + 0xb,
                2, record, zero);
        }
        break;
    }
    case 3: {
        void *record;

        record = Ov000_GetVarRecordByIndex(
            data_ov000_0205ac28->variantSource, 9);
        Ov000_DrawWithShadow_2(
            object, 0x40, 0xb, 2, record, 2);

        record = Ov000_GetVarRecordByIndex(
            data_ov000_0205ac28->variantSource,
            data_ov000_0205ac28->selectedVariant + 2);
        Ov000_DrawWithShadow_2(
            object, 0x40, 0x2a, 2, record, 2);
        break;
    }
    }

    EnqueueObjGfxCommand(object);
}

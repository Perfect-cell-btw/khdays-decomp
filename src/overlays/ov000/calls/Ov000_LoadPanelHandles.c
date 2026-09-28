typedef unsigned char u8;

typedef struct {
    u8 pad_0000[8];
    int handles[18];
    u8 pad_0050[0x4b88];
    u8 object[1];
} OverlayContext;

extern OverlayContext *NNSi_FndGetCurrentRootHeap(void);
extern int Ov000_FindEntryById(void *object, int id);

void Ov000_LoadPanelHandles(void) {
    OverlayContext *context = NNSi_FndGetCurrentRootHeap();
    int *handles = context->handles;
    int i;

    context->handles[0] = Ov000_FindEntryById(context->object, 4);
    handles[1] = Ov000_FindEntryById(context->object, 5);
    for (i = 0; i < 16; i++) {
        handles[i + 2] = Ov000_FindEntryById(context->object, i + 6);
    }
}

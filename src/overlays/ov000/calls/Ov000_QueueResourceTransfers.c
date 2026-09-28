typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 data[0x800];
} OverlayTransferBuffer;

typedef struct {
    s16 selection;
    u8 pad_0002[0x966a];
    u16 transfer_mask;
    u8 pad_966e[0x2a2];
    OverlayTransferBuffer transfer_buffers[7];
} OverlayContext;

extern const void *data_ov000_0205a970[7];
extern OverlayContext *NNSi_FndGetCurrentRootHeap(void);
extern void Ov000_OffsetHandleY(void);
extern void Ov000_RedrawVisibleMenuRows(void);
extern void Ov000_DrawListScene(void);
extern void Ov000_UploadSelectedRowGraphics(void);
extern void Ov000_ScrollListToRow(int selection);
extern void GFXi_EnqueueCommand(const void *src, int offset,
                                void *dst, u32 size);

void Ov000_QueueResourceTransfers(void) {
    OverlayContext *context = NNSi_FndGetCurrentRootHeap();
    int i;

    Ov000_OffsetHandleY();
    Ov000_RedrawVisibleMenuRows();
    Ov000_DrawListScene();
    Ov000_UploadSelectedRowGraphics();
    Ov000_ScrollListToRow(context->selection);

    for (i = 0; i < 7; i++) {
        if ((context->transfer_mask & (1 << i)) != 0) {
            GFXi_EnqueueCommand(data_ov000_0205a970[i], 0,
                                context->transfer_buffers[i].data, 0x600);
        }
    }

    context->transfer_mask = 0;
}

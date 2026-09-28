typedef unsigned char u8;
typedef signed short s16;

typedef struct {
    int x;
    int y;
} OverlayVector;

typedef struct {
    s16 value_0;
    s16 value_2;
    u8 pad_0004[0x4bd4];
    u8 object[0x8570];
    int *first_handle;
    int *second_handle;
    int *position_handle;
} OverlayContext;

extern OverlayContext *NNSi_FndGetCurrentRootHeap(void);
extern void Ov000_SetEntrySlotsVisible(void *object, int *handle, int enabled);
extern OverlayVector *Ov000_GetEntryBlock2c(void *object, int *handle);
extern void Ov000_SetEntryPosition(void *object, int *handle,
                                const OverlayVector *value);

void Ov000_OffsetHandleY(void) {
    OverlayContext *context = NNSi_FndGetCurrentRootHeap();
    OverlayVector position;

    Ov000_SetEntrySlotsVisible(context->object, context->first_handle,
                        context->value_0 != 0);
    Ov000_SetEntrySlotsVisible(context->object, context->second_handle,
                        context->value_0 < 18);

    position = *Ov000_GetEntryBlock2c(context->object,
                                    context->position_handle);
    position.y += (context->value_2 - context->value_0) << 16;
    Ov000_SetEntryPosition(context->object, context->position_handle, &position);
}

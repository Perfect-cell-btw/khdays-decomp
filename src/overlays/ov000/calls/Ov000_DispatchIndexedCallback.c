/* Copy six callbacks into locals, invoke the one selected by the index at context+0x4bc4, then
 * reset the sub-objects at +0x2c and +0x78. */

typedef unsigned char u8;
typedef void (*OverlayCallback)(void);

typedef struct {
    OverlayCallback entries[6];
} OverlayCallbackTable;

typedef struct {
    u8 pad_0000[0x2c];
    u8 object_2c[1];
    u8 pad_002d[0x4b];
    u8 object_78[1];
    u8 pad_0079[0x4b4b];
    int callback_index;
} OverlayContext;

extern const OverlayCallbackTable data_ov000_0205a86c;
extern OverlayContext *data_ov000_0205ac28;
extern void Ov000_TickSelectionWidget(void *object);
extern void Ov000_UpdateWidgetLayerDefault(void *object, int value);
extern void Ov000_FlushDirtyLogoLayers(void);

int Ov000_DispatchIndexedCallback(void) {
    OverlayCallbackTable callbacks = data_ov000_0205a86c;
    OverlayContext *context = data_ov000_0205ac28;

    callbacks.entries[context->callback_index]();
    Ov000_TickSelectionWidget(context->object_2c);
    Ov000_UpdateWidgetLayerDefault(context->object_78, 0);
    Ov000_FlushDirtyLogoLayers();
    return 0;
}

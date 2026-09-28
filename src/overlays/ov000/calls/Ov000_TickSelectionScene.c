typedef unsigned char u8;
typedef void (*OverlayCallback)(void);

typedef struct {
    OverlayCallback entries[9];
} CallbackTable;

typedef struct {
    u8 pad_0000[0x4c];
    u8 object[1];
    u8 pad_004d[0x4a83];
    int activeState;
    u8 pad_4ad4[0x2c0];
    int field4d94;
    u8 pad_4d98[0x1cb0];
    int transition;
} Ov000SceneContext;

extern const CallbackTable data_ov000_0205a710;
extern Ov000SceneContext *data_ov000_0205ac24;
extern const int data_ov000_0205a6bc[2];

extern void Ov000_PushSubWidgetValue(int enabled);
extern int Ov000_FindEntryById(int object, int id);
extern void Ov000_SetEntrySlotsVisible(int object, int entry, int enabled);
extern void Ov000_DrawLoadPageText(void);
extern void Ov000_TickPageScroll(void);
extern void Ov000_FlushDirtyLayers(void);
extern void Ov000_PlaceSelectionMarkers(void);

OverlayCallback Ov000_TickSelectionScene(void) {
    CallbackTable callbacks = data_ov000_0205a710;
    Ov000SceneContext *context = data_ov000_0205ac24;
    u8 i;
    int entry;

    if ((short)context->transition == 0 || context->activeState == 1) {
        callbacks.entries[context->activeState]();
    }

    if ((short)data_ov000_0205ac24->transition != 0) {
        Ov000_PushSubWidgetValue(0);

        for (i = 0; i < 2; i++) {
            entry = Ov000_FindEntryById(
                (int)context->object, data_ov000_0205a6bc[i]);
            Ov000_SetEntrySlotsVisible((int)context->object, entry, 0);
        }

        entry = Ov000_FindEntryById((int)context->object, 16);
        Ov000_SetEntrySlotsVisible((int)context->object, entry, 0);
        data_ov000_0205ac24->field4d94 = 0;
    }

    Ov000_DrawLoadPageText();
    Ov000_TickPageScroll();
    Ov000_FlushDirtyLayers();
    Ov000_PlaceSelectionMarkers();
    return 0;
}

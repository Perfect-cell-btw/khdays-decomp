typedef unsigned char u8;

typedef struct {
    int x;
    int y;
} OverlayVector;

typedef struct {
    u8 pad_0000[0x4c];
    u8 object_list[0x4a80];
    u8 position_shifted;
} OverlayContext;

extern OverlayContext *volatile data_ov000_0205ac24;
extern int *Ov000_FindEntryById(void *list, int id);
extern OverlayVector *Ov000_GetEntryBlock2c(void *list, int *entry);
extern void Ov000_SetEntryPosition(void *list, int *entry,
                                const OverlayVector *position);
extern void Ov000_SetEntrySlotsVisible(void *list, int *entry, int enabled);

void Ov000_PlaceCursorByMode(int enabled, int mode) {
    OverlayContext *context = data_ov000_0205ac24;
    int *entry = Ov000_FindEntryById(context->object_list, 16);
    OverlayVector position;

    if (enabled != 0) {
        position = *Ov000_GetEntryBlock2c(context->object_list, entry);
        position.x += 0x8000;

        switch (mode) {
        case 0:
            position.y = 0x2c000;
            break;
        case 1:
            position.y = 0x50000;
            break;
        case 2:
            position.y = 0x74000;
            break;
        case 3:
            position.y = 0x84000;
            break;
        }

        if (data_ov000_0205ac24->position_shifted != 0 && mode < 3) {
            position.y -= 0x8000;
        }
    }

    Ov000_SetEntryPosition(context->object_list, entry, &position);
    Ov000_SetEntrySlotsVisible(context->object_list, entry, enabled);
}

/* Resolve the handle stored at context+0x4c, then either hide it (negative value) or activate it
 * and apply a u16. The negative test is the discriminator: a negative handle means 'no entry', not
 * 'entry number -n'. */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 pad_00[0x4c];
    u8 object[1];
} OverlayContext;

extern OverlayContext *data_ov000_0205ac24;
extern int Ov000_FindEntryById(void *object, int id);
extern void Ov000_SetEntrySlotsVisible(void *object, int handle, int enabled);
extern void Ov000_ReleaseTwoSlotsEx(void *object, int handle, u16 value);

void Ov000_SetHandleActiveState(int id, int value) {
    OverlayContext *context = data_ov000_0205ac24;
    int handle = Ov000_FindEntryById(context->object, id);

    if (value >= 0) {
        Ov000_SetEntrySlotsVisible(context->object, handle, 1);
        Ov000_ReleaseTwoSlotsEx(context->object, handle, (u16)value);
    } else {
        Ov000_SetEntrySlotsVisible(context->object, handle, 0);
    }
}

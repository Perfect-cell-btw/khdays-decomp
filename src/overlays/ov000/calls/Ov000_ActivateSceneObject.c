typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;

typedef struct {
    s16 value_0;
    s16 selection;
    u8 pad_0004[0x9666];
    u16 mode_changed;
    u8 pad_966c[0x3aac];
    u8 transition_object[0x20];
    int transition_mode;
} OverlayContext;

extern void PlaySound(int first, int second);
extern void func_02020904(void);
extern void Table_TailCallWithEntry(int first, int second);
extern void Tween_Configure(void *object, int x, int y, int scale, int duration);
extern void Tween_Start(void *object);

void Ov000_ActivateSceneObject(OverlayContext *context) {
    PlaySound(0, 1);
    func_02020904();
    Table_TailCallWithEntry(0, 15);
    Tween_Configure(context->transition_object, 0, 0, 0x1000, 500);
    Tween_Start(context->transition_object);

    context->mode_changed = 0;
    switch (context->selection) {
    case 0:
        context->transition_mode = 0;
        context->mode_changed = 1;
        break;
    case 27:
        context->transition_mode = 1;
        context->mode_changed = 1;
        break;
    default:
        context->mode_changed = 0;
        break;
    }
}

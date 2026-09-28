typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int x;
    int y;
} UiLayoutPos;

typedef struct {
    u8 pad00[0x0c];
    int value0c;
} Ov008MenuEntry;

typedef struct {
    u8 pad00[4];
    u8 variables04[0x48];
    u8 surface4c[0x3c];
    int activeEntryValue88;
    u8 pad8c[0x538];
    u16 icon5c4;
} Ov008MenuPageState;

extern int Ov008_GetMenuContext(void);
extern int Ov008_GetContext(void);
extern Ov008MenuEntry *Ov008_FindEntryById(int context, int entryId);
extern UiLayoutPos *Ov008_GetEntryPos(int context, Ov008MenuEntry *entry);
extern void Ov008_SetEntryPos(int context, Ov008MenuEntry *entry,
                                UiLayoutPos *position);
extern void PlaySound(unsigned int soundId, unsigned int variant);
extern int Ov008_MapMenuObjectTypeToIcon(int value);
extern void *Ov008_GetVarRecordByIndex(void *variables, int index);
extern void Obj_InvokeInnerVtable4(void *surface);
extern void Text_DrawWithShadow(void *surface, int id, int x, int y,
                          void *buffer, int shadow);
extern void EnqueueObjGfxCommand(void *surface);

void Ov008_HandleMenuEntrySelection(Ov008MenuEntry *selectedEntry, u32 eventFlags)
{
    int context;
    Ov008MenuEntry *selectorEntry;
    int renderer;
    UiLayoutPos *selectorPosition;
    UiLayoutPos *selectedPosition;
    void *buffer;
    int previousValue;
    int icon;
    UiLayoutPos position;

    renderer = Ov008_GetMenuContext();
    if ((eventFlags & 0xf0) == 0) {
        return;
    }

    context = Ov008_GetContext();
    selectorEntry = Ov008_FindEntryById(context, 0x15);
    selectorPosition = Ov008_GetEntryPos(context, selectorEntry);
    selectedPosition = Ov008_GetEntryPos(context, selectedEntry);
    if ((u32)(selectedEntry->value0c - 7) <= 1) {
        position.x = selectedPosition->x - 0x30000;
        position.y = selectedPosition->y;
    } else {
        position.x = selectorPosition->x;
        position.y = selectedPosition->y;
    }
    Ov008_SetEntryPos(context, selectorEntry, &position);

    previousValue = *(int *)(renderer + 0x88);
    if (previousValue != -1 && previousValue != selectedEntry->value0c) {
        PlaySound(0, 0);
    }
    *(int *)(renderer + 0x88) = selectedEntry->value0c;

    icon = Ov008_MapMenuObjectTypeToIcon(selectedEntry->value0c);
    if (icon >= 0) {
        *(u16 *)(renderer + 0x5c4) = (u16)icon;
    }
    if (icon < 0) {
        return;
    }
    buffer = Ov008_GetVarRecordByIndex((void *)(renderer + 4), icon);
    Obj_InvokeInnerVtable4((void *)(renderer + 0x4c));
    Text_DrawWithShadow((void *)(renderer + 0x4c), 0x56, 0, 2, buffer, 1);
    EnqueueObjGfxCommand((void *)(renderer + 0x4c));
}

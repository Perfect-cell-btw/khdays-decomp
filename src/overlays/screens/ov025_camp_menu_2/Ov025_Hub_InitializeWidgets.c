/* Builds the camp menu hub's widgets: loads its layout, sets the entries' frames and visibility
 * from the progress, and installs each entry's callback. */

typedef unsigned int u32;
typedef unsigned short u16;
typedef struct Ov025LayoutTemplate { u32 words[4]; } Ov025LayoutTemplate;
extern const Ov025LayoutTemplate data_ov025_020b3894;
extern int Ov025_GetContext(void);
extern u32 Ov025_PackSlotTag(int tag);
extern void *Ov025_PackHandleTagB(int index);
extern void Ov025_InitFromDescAndMark(int context, Ov025LayoutTemplate *layout);
extern void func_ov025_02088410(int context, void *resource);
extern void Ov025_LoadBlockProcessAndFree(int context, void *resource, int size);
extern void Ov025_StoreWordAt0x4a50(int context, void *callback);
extern void *Ov025_FindEntryById(int context, int id);
extern void Ov025_ReleaseTwoSlots(int context, void *entry);
extern void Ov025_ReleaseTwoSlotsEx_2(int context, void *entry, u16 frame);
extern void Ov025_SetEntrySlotsVisible(int context, void *entry, int visible);
extern void Ov025_ResolveEntryStoreWord(int context, int id, void *callback);
extern int GameState_GetField(int field, int bits);
extern void Ov025_Hub_InitEntries(void *scene);
extern void Ov025_Hub_OnEntryHover(void);
extern void Ov025_MenuEntry_SetSlot2AndBeep(void);
extern void Ov025_ConfirmMenuItem(void);
extern void Ov025_DispatchIfRngHigh(void);
extern void Ov025_GoToPage6WithCue(void);
extern void Ov025_GoToPage5(void);
extern void Ov025_GoToPage4(void);
extern void Ov025_Hub_OpenSubMenu(void);
extern void Ov025_MenuConfirmTransition(void);
extern void Ov025_InitSequence(void);
extern void Ov025_Hub_SelectEntry(void);
extern void Ov025_Hub_CloseSubMenu(void);
extern void Ov025_GoToPage7A(void);
extern void Ov025_GoToPage7B(void);
extern void Ov025_HubWidgetCallbackNoOp(void);
extern void Ov025_HubWidgetCallbackNoOp_2(void);
extern void Ov025_HubWidgetCallbackNoOp_3(void);
extern void Ov025_HubWidgetCallbackNoOp_4(void);
extern void Ov025_HubWidgetCallbackNoOp_5(void);
extern void Ov025_HubWidgetCallbackNoOp_6(void);
extern void Ov025_HubWidgetCallbackNoOp_7(void);

void Ov025_Hub_InitializeWidgets(void *scene)
{
    Ov025LayoutTemplate layout = data_ov025_020b3894;
    int context = Ov025_GetContext();
    void *resource;
    int day;
    int tens;
    int hundreds;
    layout.words[0] = Ov025_PackSlotTag(0xb);
    Ov025_InitFromDescAndMark(context, &layout);
    resource = Ov025_PackHandleTagB(1);
    if (resource != 0) func_ov025_02088410(context, resource);
    Ov025_LoadBlockProcessAndFree(context, (void *)Ov025_PackSlotTag(0xc), 0x34);
    Ov025_StoreWordAt0x4a50(context, (void *)Ov025_Hub_OnEntryHover);
    Ov025_Hub_InitEntries(scene);
    Ov025_ReleaseTwoSlots(context, Ov025_FindEntryById(context, 0x2a));
    Ov025_ReleaseTwoSlots(context, Ov025_FindEntryById(context, 0x2b));
    Ov025_ReleaseTwoSlots(context, Ov025_FindEntryById(context, 0x2c));
    day = GameState_GetField(0, 9);
    Ov025_ReleaseTwoSlotsEx_2(context, Ov025_FindEntryById(context, 0x2a), day % 10);
    tens = day / 10;
    if (tens > 0)
        Ov025_ReleaseTwoSlotsEx_2(context, Ov025_FindEntryById(context, 0x2b), tens % 10);
    else
        Ov025_SetEntrySlotsVisible(context, Ov025_FindEntryById(context, 0x2b), 0);
    tens = tens / 10; hundreds = tens;
    if (hundreds > 0)
        Ov025_ReleaseTwoSlotsEx_2(context, Ov025_FindEntryById(context, 0x2c), hundreds);
    else
        Ov025_SetEntrySlotsVisible(context, Ov025_FindEntryById(context, 0x2c), 0);
    Ov025_ResolveEntryStoreWord(context, 1, (void *)Ov025_MenuEntry_SetSlot2AndBeep);
    Ov025_ResolveEntryStoreWord(context, 2, (void *)Ov025_ConfirmMenuItem);
    Ov025_ResolveEntryStoreWord(context, 3, (void *)Ov025_DispatchIfRngHigh);
    Ov025_ResolveEntryStoreWord(context, 4, (void *)Ov025_GoToPage6WithCue);
    Ov025_ResolveEntryStoreWord(context, 5, (void *)Ov025_GoToPage5);
    Ov025_ResolveEntryStoreWord(context, 6, (void *)Ov025_GoToPage4);
    Ov025_ResolveEntryStoreWord(context, 9, (void *)Ov025_Hub_OpenSubMenu);
    Ov025_ResolveEntryStoreWord(context, 10, (void *)Ov025_MenuConfirmTransition);
    Ov025_ResolveEntryStoreWord(context, 11, (void *)Ov025_InitSequence);
    Ov025_ResolveEntryStoreWord(context, 7, (void *)Ov025_Hub_SelectEntry);
    Ov025_ResolveEntryStoreWord(context, 8, (void *)Ov025_Hub_CloseSubMenu);
    Ov025_ResolveEntryStoreWord(context, 12, (void *)Ov025_GoToPage7A);
    Ov025_ResolveEntryStoreWord(context, 13, (void *)Ov025_GoToPage7B);
    Ov025_ResolveEntryStoreWord(context, 0x65, (void *)Ov025_HubWidgetCallbackNoOp);
    Ov025_ResolveEntryStoreWord(context, 0x66, (void *)Ov025_HubWidgetCallbackNoOp_2);
    Ov025_ResolveEntryStoreWord(context, 0x67, (void *)Ov025_HubWidgetCallbackNoOp_3);
    Ov025_ResolveEntryStoreWord(context, 0x68, (void *)Ov025_HubWidgetCallbackNoOp_4);
    Ov025_ResolveEntryStoreWord(context, 0x69, (void *)Ov025_HubWidgetCallbackNoOp_5);
    Ov025_ResolveEntryStoreWord(context, 0x6a, (void *)Ov025_HubWidgetCallbackNoOp_6);
    Ov025_ResolveEntryStoreWord(context, 0x6b, (void *)Ov025_HubWidgetCallbackNoOp_7);
}

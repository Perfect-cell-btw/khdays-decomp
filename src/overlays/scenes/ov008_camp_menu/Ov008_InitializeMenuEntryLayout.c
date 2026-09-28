/* Builds the camp menu's entry layout: loads its layout and resources, hides the optional entries,
 * and installs each entry's selection callback. */

#include "nitro/types.h"

typedef struct Ov008LayoutTemplate {
    u32 words[4];
} Ov008LayoutTemplate;

extern Ov008LayoutTemplate data_ov008_0208e918;

extern int Ov008_GetContext(void);
extern int Ov008_PackSlotTag(int tag);
extern void *Ov008_PackHandleTagB(int index);
extern void Ov008_InitFromDescAndMark(int context, Ov008LayoutTemplate *layout);
extern void func_ov008_0205475c(int context, void *resource);
extern void Ov008_LoadBlockProcessAndFree(int context, void *resource, int size);
extern void Ov008_StoreWordAt0x4a50(int context, void *callback);
extern int Ov008_FindEntryById(int context, int id);
extern void Ov008_SetEntrySlotsVisible(int context, int entry, int visible);
extern void Ov008_ResolveEntryStoreWord(int context, int id, void *callback);

extern void Ov008_HandleMenuEntrySelection(void);
extern void Ov008_MenuEntry_SetSlot2AndBeep(void);
extern void Ov008_ConfirmMenuItem(void);
extern void Ov008_CharMenuConfirm(void);
extern void Ov008_GoToPage6WithCue(void);
extern void Ov008_GoToPage5(void);
extern void Ov008_GoToPage4(void);
extern void Ov008_MenuEntryWidgetCallbackNoOp(void);
extern void Ov008_MenuConfirmTransition(void);
extern void Ov008_InitSequence(void);
extern void Ov008_RequestMode7(void);
extern void Ov008_MenuEntry_Cancel(void);
extern void Ov008_GoToPage7A(void);
extern void Ov008_GoToPage7B(void);
extern void Ov008_EnterMode1(void);
extern void Ov008_RequestMode2(void);
extern void Ov008_RequestMode3(void);
extern void Ov008_RequestMode4(void);
extern void Ov008_RequestMode5(void);
extern void Ov008_GoToPage4FromCursor(void);
extern void Ov008_ToggleDetailPanelWithSound(void);

void Ov008_InitializeMenuEntryLayout(void)
{
    Ov008LayoutTemplate layout = data_ov008_0208e918;
    int context = Ov008_GetContext();
    void *resource;

    layout.words[0] = Ov008_PackSlotTag(0xb);
    Ov008_InitFromDescAndMark(context, &layout);
    resource = Ov008_PackHandleTagB(1);
    if (resource != 0) {
        func_ov008_0205475c(context, resource);
    }
    Ov008_LoadBlockProcessAndFree(context, (void *)Ov008_PackSlotTag(0xc), 0x34);
    Ov008_StoreWordAt0x4a50(context, (void *)Ov008_HandleMenuEntrySelection);

    Ov008_SetEntrySlotsVisible(context, Ov008_FindEntryById(context, 0x1f), 0);
    Ov008_SetEntrySlotsVisible(context, Ov008_FindEntryById(context, 2), 0);
    Ov008_SetEntrySlotsVisible(context, Ov008_FindEntryById(context, 1), 0);
    Ov008_SetEntrySlotsVisible(context, Ov008_FindEntryById(context, 3), 0);
    Ov008_SetEntrySlotsVisible(context, Ov008_FindEntryById(context, 4), 0);
    Ov008_SetEntrySlotsVisible(context, Ov008_FindEntryById(context, 5), 0);
    Ov008_SetEntrySlotsVisible(context, Ov008_FindEntryById(context, 6), 0);
    Ov008_SetEntrySlotsVisible(context, Ov008_FindEntryById(context, 9), 0);
    Ov008_SetEntrySlotsVisible(context, Ov008_FindEntryById(context, 0x29), 0);
    Ov008_SetEntrySlotsVisible(context, Ov008_FindEntryById(context, 0x2a), 0);
    Ov008_SetEntrySlotsVisible(context, Ov008_FindEntryById(context, 0x2b), 0);
    Ov008_SetEntrySlotsVisible(context, Ov008_FindEntryById(context, 0x2c), 0);
    Ov008_SetEntrySlotsVisible(context, Ov008_FindEntryById(context, 0x64), 1);
    Ov008_SetEntrySlotsVisible(context, Ov008_FindEntryById(context, 0x65), 1);
    Ov008_SetEntrySlotsVisible(context, Ov008_FindEntryById(context, 0x66), 1);
    Ov008_SetEntrySlotsVisible(context, Ov008_FindEntryById(context, 0x67), 1);
    Ov008_SetEntrySlotsVisible(context, Ov008_FindEntryById(context, 0x68), 1);
    Ov008_SetEntrySlotsVisible(context, Ov008_FindEntryById(context, 0x69), 1);
    Ov008_SetEntrySlotsVisible(context, Ov008_FindEntryById(context, 0x6a), 1);
    Ov008_SetEntrySlotsVisible(context, Ov008_FindEntryById(context, 0x6b), 1);

    Ov008_ResolveEntryStoreWord(context, 1, (void *)Ov008_MenuEntry_SetSlot2AndBeep);
    Ov008_ResolveEntryStoreWord(context, 2, (void *)Ov008_ConfirmMenuItem);
    Ov008_ResolveEntryStoreWord(context, 3, (void *)Ov008_CharMenuConfirm);
    Ov008_ResolveEntryStoreWord(context, 4, (void *)Ov008_GoToPage6WithCue);
    Ov008_ResolveEntryStoreWord(context, 5, (void *)Ov008_GoToPage5);
    Ov008_ResolveEntryStoreWord(context, 6, (void *)Ov008_GoToPage4);
    Ov008_ResolveEntryStoreWord(context, 9, (void *)Ov008_MenuEntryWidgetCallbackNoOp);
    Ov008_ResolveEntryStoreWord(context, 10, (void *)Ov008_MenuConfirmTransition);
    Ov008_ResolveEntryStoreWord(context, 11, (void *)Ov008_InitSequence);
    Ov008_ResolveEntryStoreWord(context, 7, (void *)Ov008_RequestMode7);
    Ov008_ResolveEntryStoreWord(context, 8, (void *)Ov008_MenuEntry_Cancel);
    Ov008_ResolveEntryStoreWord(context, 12, (void *)Ov008_GoToPage7A);
    Ov008_ResolveEntryStoreWord(context, 13, (void *)Ov008_GoToPage7B);
    Ov008_ResolveEntryStoreWord(context, 0x65, (void *)Ov008_EnterMode1);
    Ov008_ResolveEntryStoreWord(context, 0x66, (void *)Ov008_RequestMode2);
    Ov008_ResolveEntryStoreWord(context, 0x67, (void *)Ov008_RequestMode3);
    Ov008_ResolveEntryStoreWord(context, 0x68, (void *)Ov008_RequestMode4);
    Ov008_ResolveEntryStoreWord(context, 0x69, (void *)Ov008_RequestMode5);
    Ov008_ResolveEntryStoreWord(context, 0x6a, (void *)Ov008_GoToPage4FromCursor);
    Ov008_ResolveEntryStoreWord(context, 0x6b, (void *)Ov008_ToggleDetailPanelWithSound);
}

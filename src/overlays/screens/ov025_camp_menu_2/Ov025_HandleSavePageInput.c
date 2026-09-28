typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Ov008MenuEntry {
    u8 pad00[0x0c];
    int entryId;
} Ov008MenuEntry;

typedef struct Ov008MenuContext {
    u8 pad0000[0x08];
    int menuMode;
    u8 pad000c[0x10 - 0x0c];
    int menuState;
    u8 pad0014[0x20 - 0x14];
    int selectedSavePage;
    u8 pad0024[0xa4 - 0x24];
    int pendingActionCode;
    u8 pad00a8[0x28c - 0xa8];
    u8 savePageTextRecords;
} Ov008MenuContext;

extern Ov008MenuContext *Ov025_GetPageA(void);
extern void Ov025_ConfigureSlotWithHeight(Ov008MenuEntry *entry);
extern void *Ov025_GetVarRecordByIndex(void *records, int index);
extern void Ov025_RepaintTextRow(
    Ov008MenuContext *context, int row, void *text, int mode);
extern void PlaySound(int arg0, int arg1);
extern void Ov025_DrawSavePage(
    Ov008MenuContext *context, int savePage);

void Ov025_HandleSavePageInput(Ov008MenuEntry *entry, u32 inputFlags)
{
    Ov008MenuContext *context = Ov025_GetPageA();
    int previousSavePage;
    void *captionRecord;
    int captionRecordIndex;

    if (entry == 0) {
        return;
    }
    if ((inputFlags & 0x40) == 0 && (inputFlags & 0x80) == 0) {
        return;
    }

    Ov025_ConfigureSlotWithHeight(entry);
    if (context->menuState != 2 || context->menuMode != 1) {
        return;
    }

    switch (context->pendingActionCode) {
    case 0:
        switch (entry->entryId) {
        case 0x50:
            captionRecordIndex = 8;
            break;
        case 0x51:
            captionRecordIndex = 7;
            break;
        case 0x52:
            captionRecordIndex = 9;
            break;
        case 0x53:
            captionRecordIndex = 10;
            break;
        case 0x54:
            captionRecordIndex = 11;
            break;
        default:
            captionRecordIndex = 7;
            break;
        }
        captionRecord = Ov025_GetVarRecordByIndex(
            &context->savePageTextRecords, captionRecordIndex);
        Ov025_RepaintTextRow(context, 0, captionRecord, 0xf3);
        PlaySound(0, 0);
        return;

    case 1:
    case 4:
        previousSavePage = context->selectedSavePage;
        switch (entry->entryId) {
        case 0x59:
        case 0x5d:
            context->selectedSavePage = 0;
            break;
        case 0x5a:
        case 0x5e:
            context->selectedSavePage = 1;
            break;
        case 0x5b:
        case 0x5f:
            context->selectedSavePage = 2;
            break;
        default:
            context->selectedSavePage = 0;
            break;
        }
        Ov025_DrawSavePage(context, context->selectedSavePage);
        if (previousSavePage == context->selectedSavePage) {
            return;
        }
        PlaySound(0, 0);
        return;

    case 3:
        break;

    case 6:
        break;

    case 8:
        break;

    default:
        PlaySound(0, 0);
        return;
    }
}



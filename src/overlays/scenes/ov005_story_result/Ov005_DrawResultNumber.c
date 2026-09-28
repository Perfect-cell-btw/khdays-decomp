/* Select decimal digit sequences and hide slots beyond the requested width. */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct Ov005SpriteManager { char data[0x4a80]; } Ov005SpriteManager;
typedef struct Ov005ResultContext { char unknown00[0x54]; Ov005SpriteManager spriteManager; } Ov005ResultContext;
extern Ov005ResultContext *data_ov005_0205b810;
extern int Ov005_CountDecimalDigits(int);
extern int Ov005_ExtractDecimalDigit(int, u32);
extern void *Ov005_FindEntryById(Ov005SpriteManager *, int);
extern void Ov005_ReleaseTwoSlotsEx_2(Ov005SpriteManager *, void *, u32);
extern void Ov005_SetEntrySlotsVisible(Ov005SpriteManager *, void *, int);
void Ov005_DrawResultNumber(u32 value, int firstEntryId, int capacity, int minimumDigits) {
    Ov005ResultContext *context = data_ov005_0205b810;
    u8 index, digitCount;
    digitCount = Ov005_CountDecimalDigits(value);
    for (index = 0; index < capacity; index++) {
        void *entry = Ov005_FindEntryById(&context->spriteManager, firstEntryId + index);
        Ov005_ReleaseTwoSlotsEx_2(&context->spriteManager, entry, (u8)Ov005_ExtractDecimalDigit(index, value));
        if (index < digitCount) Ov005_SetEntrySlotsVisible(&context->spriteManager, entry, 1);
        else Ov005_SetEntrySlotsVisible(&context->spriteManager, entry, index < minimumDigits);
    }
}

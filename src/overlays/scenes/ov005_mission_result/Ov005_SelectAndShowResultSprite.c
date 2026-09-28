/* Select a sequence on a result sprite's slots and make the entry visible. */
typedef struct Ov005SpriteManager { char data[0x4a80]; } Ov005SpriteManager;
typedef struct Ov005ResultContext { char unknown00[0x54]; Ov005SpriteManager spriteManager; } Ov005ResultContext;
extern Ov005ResultContext *data_ov005_0205b810;
extern void *Ov005_FindEntryById(Ov005SpriteManager *, int);
extern void Ov005_ReleaseTwoSlotsEx_2(Ov005SpriteManager *, void *, unsigned int);
extern void Ov005_SetEntrySlotsVisible(Ov005SpriteManager *, void *, int);
void Ov005_SelectAndShowResultSprite(int entryId, unsigned int sequenceIndex) {
    void *entry = Ov005_FindEntryById(&data_ov005_0205b810->spriteManager, entryId);
    Ov005_ReleaseTwoSlotsEx_2(&data_ov005_0205b810->spriteManager, entry, sequenceIndex);
    entry = Ov005_FindEntryById(&data_ov005_0205b810->spriteManager, entryId);
    Ov005_SetEntrySlotsVisible(&data_ov005_0205b810->spriteManager, entry, 1);
}

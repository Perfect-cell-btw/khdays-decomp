/* Teardown: release the two model handles, then the five 8-byte attachment
 * slots at +0x3dc (only the first word of each pair owns anything), free the
 * slot block and let the base class finish. */
extern void DestroyInstance(void *handle);
extern void Ov107_ActionResource_Destroy(void *model);
extern void FreeInstanceMemory(void *block);
extern void Ov107_DestroyObject(void *self);

typedef struct {
    void *pHandle;
    void *pExtra;
} Ov202Slot;

typedef struct {
    char pad0000[0x384];
    void *pModelA;      /* +0x384 */
    void *pModelB;      /* +0x388 */
    char pad038c[0x50];
    Ov202Slot *pSlots;  /* +0x3dc */
} Ov202Object;

void Ov203_Destroy(Ov202Object *self) {
    int i;

    DestroyInstance(self->pModelA);
    Ov107_ActionResource_Destroy(self->pModelB);

    for (i = 0; i < 5; i++) {
        DestroyInstance(self->pSlots[i].pHandle);
    }

    FreeInstanceMemory(self->pSlots);
    Ov107_DestroyObject(self);
}

/* Create and start the next external object slot, then return its index. */
typedef unsigned char u8;

typedef struct Ov107Object {
    u8 gap0000[0x44];
    void (*pCallback)(void);
} Ov107Object;

typedef struct Ov002ObjectSlot {
    Ov107Object *pObject;
    u8 gap0004[0x13];
    u8 nSourceIndex;
} Ov002ObjectSlot;

typedef struct Ov002ObjectContext {
    u8 gap0000[0x1c];
    void *aSources[10];
    Ov002ObjectSlot *pSlots;
    u8 gap0048;
    u8 nSlotCount;
} Ov002ObjectContext;

extern Ov002ObjectContext *data_ov002_0207fa14;

extern Ov107Object *Ov107_CreateMovementNode(void);
extern void Ov107_InitObjectFromSource(void *pSource, Ov107Object *pObject);
extern void Ov107_StartObject(Ov107Object *pObject);
extern void Ov002_OnObjectEvent(void);

int Ov002_CreateObjectSlot(int nSourceIndex)
{
    Ov002ObjectContext *pContext = data_ov002_0207fa14;
    u8 nSlot = pContext->nSlotCount;

    pContext->pSlots[nSlot].pObject = Ov107_CreateMovementNode();
    Ov107_InitObjectFromSource(pContext->aSources[nSourceIndex],
                        pContext->pSlots[nSlot].pObject);
    pContext->pSlots[nSlot].pObject->pCallback = Ov002_OnObjectEvent;
    pContext->pSlots[nSlot].nSourceIndex = (u8)nSourceIndex;
    Ov107_StartObject(pContext->pSlots[nSlot].pObject);
    pContext->nSlotCount++;
    return nSlot;
}

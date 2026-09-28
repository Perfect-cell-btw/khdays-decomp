typedef unsigned short u16;

/* The queue record the collector fills in. */
typedef struct {
    unsigned char bTag;             /* +0x00 */
    unsigned char bSource;          /* +0x01 filled by the collector */
    u16 wIndex;                     /* +0x02 filled by the collector */
    unsigned char bValue;           /* +0x04 */
    unsigned char bPad[3];          /* +0x05 */
} Ov002HitRecord;

typedef void *(*Ov002ElementProc)(char *pElement);

extern short Session_GetLocalPlayerIndex(void);
extern int GameState_GetField(u16 nId, unsigned char nSlot);
extern int Ov002_RecordElementHit(char *pElement, Ov002HitRecord *pRecord, int nKind);
extern void *Ov002_ElementTickFinishing(char *pElement);

void *Ov002_ElementPhase_WatchStateBit(char *pElement)
{
    Ov002HitRecord rec;
    unsigned int nState;
    unsigned int nBit;

    switch (*(unsigned char *)(pElement + 0x1c1)) {
    case 0:
        if (Session_GetLocalPlayerIndex() != 0) {
            return 0;
        }

        nState = ((unsigned int)(GameState_GetField(*(u16 *)(pElement + 0x14),
                                       *(unsigned char *)(pElement + 0x16))
                                 & 0xfffe) << 15) >> 16;
        nBit = nState & 1;

        if (nBit != *(unsigned char *)(pElement + 0x1c2)
            && *(unsigned char *)(pElement + 0x1c1) != 2) {
            rec.bTag = 1;
            rec.bValue = (nBit == 1) ? 3 : 1;

            if (Ov002_RecordElementHit(pElement, &rec, 6) != 0) {
                *(unsigned char *)(pElement + 0x1c1) = 1;
                *(unsigned char *)(pElement + 0x1c2) = (unsigned char)nBit;
            }
        }
        break;

    case 2:
        return Ov002_ElementTickFinishing;
    }

    return 0;
}

/*
 * Redraws the map panel for one frame.
 *
 * The blink phase is advanced first on its own tick budget, then the tile buffer
 * is cleared and rebuilt: the fixed markers, the goal marker when one is set, the
 * panel decorations, every visible entity's icon, and finally the party rows and
 * the local player's emblem. The finished buffer is handed to the graphics queue.
 *
 * Entities are walked backwards through the room's list and filtered on three
 * flags: the low byte at +0x60 must have bit 0 set and bit 7 clear, the halfword
 * at +0x1ac must not have bit 1 set, and bit 2 there hides an entity unless its
 * icon kind is six.
 *
 * Two things here are load-bearing rather than style.
 *
 * The local player's id is read twice and kept in two separate variables: a
 * halfword for the room lookup and an int for the party block. Folding them into
 * one variable transposes the two scratch registers the party block hands to the
 * id and to the team, and moves six bytes. The two reads are genuinely separate
 * fetches in the ROM, so one variable each is also the honest reading.
 *
 * The count, the id, the team and the loop index are declared ahead of everything
 * else, in that order. That is what puts them in r5, r6, r7 and r8 rather than
 * letting the blink block's register pair push them apart.
 *
 * ARM.
 */
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Ov002MapScene {
    char pad000[0x1c];
    void *pTiles;
    u8 nMode;
    char pad021[0x17];
    unsigned long long llBlinkAt;
    int bBlinkOn;
} Ov002MapScene;

typedef struct Ov002MapEntry {
    char pad000[0xc];
} Ov002MapEntry;

typedef struct Ov002RoomEntity {
    char pad000[0x60];
    u16 nFlags;
    char pad062[0x117];
    u8 nIconKind;
    char pad17a[0x32];
    u16 nHideFlags;
} Ov002RoomEntity;

typedef struct Ov002RoomList {
    char pad000[0x80];
    char aList[4];
} Ov002RoomList;

typedef struct Ov002RoomRef {
    char pad000[4];
    Ov002RoomList *pRoom;
} Ov002RoomRef;

typedef struct Ov002RoomHolder {
    char pad000[0x4ec];
    Ov002RoomRef *pRef;
} Ov002RoomHolder;

extern Ov002MapScene *data_ov002_0207f638;
extern Ov002MapEntry data_ov002_0207f69c[];
extern Ov002MapEntry data_ov002_0207f63c[];

extern unsigned long long OS_GetTick(void);
extern unsigned long long func_02020374(unsigned long long a,
                                            unsigned long long b);
extern void MIi_CpuClearFast(unsigned int data, void *dest, unsigned int size);
extern void Ov002_UpdateCursorCell(void);
extern int Ov002_CollectObjectPositionsOfKind(Ov002MapEntry *pTable);
extern int Ov002_IsMapEntryActionable(int nAxis, int nIndex);
extern void Ov002_DrawIntoScratch(Ov002MapEntry *pEntry, int bWide, int nVariant);
extern int Ov002_Field_HasSpawnPos(void);
extern int Ov002_Field_GetSpawnPos(void);
extern int Ov002_StampCellBlockA(int nGoal);
extern int Ov002_CopyLinkItemPositions(Ov002MapEntry *pTable);
extern int Ov002_StampCellBlockB(Ov002MapEntry *pEntry);
extern u16 QueryActiveStateOrDelegate(void);
extern Ov002RoomHolder *GetEntryField20ByIndex(unsigned int nSelf);
extern void *List_Last(void *pList);
extern void *List_Prev(void *pList);
extern void Ov002_ScreenToCell(int *aCell, const void *pPos);
extern void Ov002_PlotMapIcon(int nKind, const int *aCell);
extern int func_ov022_020882f8(void);
extern int Ov022_GetEntryField66(int nPlayer);
extern int Ov022_GetEntryField12(int nPlayer);
extern void Ov002_FormatRowFromSelection(int nPlayer);
extern void Ov002_PlotPageEmblem(int nPlayer);
extern int GFXi_EnqueueCommand(int nCommand, int nTarget, void *pSrc,
                               int nSize);

void Ov002_RedrawMapPanel(void)
{
    int nPlayers;
    int nSelf;
    int nMine;
    int i;
    Ov002MapScene *pScene;
    unsigned long long llNow;
    unsigned long long llDelta;
    int nCount;
    int bWide;
    int nVariant;
    Ov002RoomHolder *pHolder;
    Ov002RoomList *pRoom;
    Ov002RoomEntity *pEntity;
    void *pNode;
    int aCell[2];
    unsigned int nLow;
    u16 nHide;
    u16 nRoomSelf;

    pScene = data_ov002_0207f638;
    llNow = OS_GetTick();
    llDelta = llNow - pScene->llBlinkAt;
    if (llDelta > 0x3fec4) {
        pScene->llBlinkAt = llNow - func_02020374(llDelta, 0x3fec4);
        pScene->bBlinkOn = pScene->bBlinkOn == 0;
    }

    Ov002_UpdateCursorCell();
    MIi_CpuClearFast(0, pScene->pTiles, 0x12c0);

    if (pScene->nMode < 2) {
        nCount = Ov002_CollectObjectPositionsOfKind(data_ov002_0207f69c);
        for (i = 0; i < nCount; i++) {
            bWide = Ov002_IsMapEntryActionable(0, i);
            nVariant = Ov002_IsMapEntryActionable(1, i);
            Ov002_DrawIntoScratch(&data_ov002_0207f69c[i], bWide, nVariant);
        }

        if (Ov002_Field_HasSpawnPos() != 0) {
            Ov002_StampCellBlockA(Ov002_Field_GetSpawnPos());
        }

        nCount = Ov002_CopyLinkItemPositions(data_ov002_0207f63c);
        for (i = 0; i < nCount; i++) {
            Ov002_StampCellBlockB(&data_ov002_0207f63c[i]);
        }

        nRoomSelf = QueryActiveStateOrDelegate();
        pHolder = GetEntryField20ByIndex(nRoomSelf);
        if (pHolder != 0 && pHolder->pRef != 0
            && pHolder->pRef->pRoom != 0) {
            pRoom = pHolder->pRef->pRoom;
            pNode = List_Last(pRoom->aList);
            pEntity = pNode == 0 ? 0 : *(Ov002RoomEntity **)pNode;
            while (pEntity != 0) {
                nHide = pEntity->nHideFlags;
                nLow = (unsigned int)(pEntity->nFlags << 24) >> 24;
                if ((nLow & 1) && !(nLow & 0x80) && !(nHide & 2)
                    && (pEntity->nIconKind == 6 || !(nHide & 4))) {
                    Ov002_ScreenToCell(aCell, (char *)pEntity + 0x74);
                    Ov002_PlotMapIcon(pEntity->nIconKind, aCell);
                }
                pNode = List_Prev(pRoom->aList);
                pEntity = pNode == 0 ? 0 : *(Ov002RoomEntity **)pNode;
            }
        }

        nPlayers = func_ov022_020882f8();
        nSelf = QueryActiveStateOrDelegate();
        nMine = Ov022_GetEntryField66(nSelf);
        for (i = 0; i < nPlayers; i++) {
            if (i != nSelf && Ov022_GetEntryField66(i) == nMine && Ov022_GetEntryField12(i) > 0) {
                Ov002_FormatRowFromSelection(i);
            }
        }
        Ov002_FormatRowFromSelection(nSelf);
        Ov002_PlotPageEmblem(nSelf);
    }

    GFXi_EnqueueCommand(0x16, 0x2720, pScene->pTiles, 0x12c0);
}

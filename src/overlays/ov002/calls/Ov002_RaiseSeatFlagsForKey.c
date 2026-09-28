typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;

extern char *data_ov002_0207fa00;
extern u8 data_0204c240;                /* g_modeAndDayClock; bit 1 blocks this */

extern int Ov002_GetStateWord(void);           /* the key for this state */
extern void Ov002_LoadOffsetTableOnce(int nWhich);    /* load the table */
extern char *Ov002_FindHandlerByKey(int nKey);     /* find the key's row set */
extern void Ov002_FreeRootBuffer0x8d7c(void);          /* let the table go */
extern int GameState_IsFlagSet(int nFlag);
extern void GameState_SetFlag(int nFlag);

/* Raises the flag for every row of the current key whose seat is present.
 *
 * The key's row set is looked up in the offset table, which is loaded for the
 * call and released again on the way out, on every path once the mode allows
 * it at all.  A row is skipped when its flag is already up, and otherwise only
 * fires when the seat mask has that row's seat bit.  The flag id is the row's
 * own id plus nine.
 *
 * Ghidra models the rows as Ov002OffsetRow, 0x14 apart, with the count in the
 * first row's own +2; the seat mask is root +0x8d80, reached here through the
 * pOffsetTable field just above it as a base plus four, which is why that
 * pointer is never dereferenced.
 */
void Ov002_RaiseSeatFlagsForKey(void)
{
    char *pRoot;
    char *pBlock;
    char *pRows;
    int nKey;
    int i;
    char *pRow;

    pRoot = data_ov002_0207fa00;
    pBlock = pRoot + 0x8d7c;
    nKey = Ov002_GetStateWord();

    if ((data_0204c240 & 2) == 0) {
        Ov002_LoadOffsetTableOnce(0);
        pRows = Ov002_FindHandlerByKey(nKey);
        if (pRows != 0) {
            i = 0;
            if (*(s8 *)(pRows + 2) > 0) {
                pRow = pRows;
                do {
                    if (GameState_IsFlagSet(*(s16 *)(pRow + 8) + 9) == 0
                        && (*(u16 *)(pBlock + 4)
                            & (1 << *(s8 *)(pRow + 4))) != 0) {
                        GameState_SetFlag(*(s16 *)(pRow + 8) + 9);
                    }
                    i++;
                    pRow += 0x14;
                } while (i < *(s8 *)(pRows + 2));
            }
        }
        Ov002_FreeRootBuffer0x8d7c();
    }
}

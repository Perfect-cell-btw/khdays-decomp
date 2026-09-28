/* Ov025_DispatchFrom2DTable -- Ov008_DispatchFrom2DTable: pick sub-entry nColumn of menu entry nItem
 * (data_ov025_020b4f64) and hand its id to Ov008_Set_9bec (0209bfcc) for the widget pick; the
 * two context getters are called first (their results unused). */
typedef unsigned char u8;
typedef short s16;

typedef struct Ov008MenuSubEntry {
    s16 nId;                  /* 0x00 */
    u8  nText;                /* 0x02 */
    u8  nHelpText;            /* 0x03 */
} Ov008MenuSubEntry;

typedef struct Ov008MenuEntryDef {
    s16 nId;                  /* 0x00 */
    u8  nText;                /* 0x02 */
    u8  nHelpText;            /* 0x03 */
    u8  nAnchor;              /* 0x04 */
    u8  nState;               /* 0x05: lock state */
    u8  bEnabled;             /* 0x06 */
    u8  nSubCount;            /* 0x07 */
    Ov008MenuSubEntry aSub[3]; /* 0x08 */
} Ov008MenuEntryDef;

extern Ov008MenuEntryDef data_ov025_020b4f64[];                    /* the menu entry table */

extern void *Ov025_GetPageA(void);                             /* Ov008_GetMenuContext */
extern int   Ov025_GetContext(void);                             /* Ov008_GetContext */
extern void  Ov025_WidgetRef_Init(short *pPick, s16 nId);            /* Ov008_Set_9bec */

void Ov025_DispatchFrom2DTable(short *pPick, short nItem, int nColumn)
{
    Ov025_GetPageA();
    Ov025_GetContext();
    Ov025_WidgetRef_Init(pPick, data_ov025_020b4f64[nItem].aSub[nColumn].nId);
}

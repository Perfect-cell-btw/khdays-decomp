/* Initialises a widget reference from the menu table's sub-entry id. */

extern void Ov008_GetMenuContext(void);
extern void Ov008_GetContext(void);
extern void Ov008_WidgetRef_Init(int arg0, int arg1);
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

extern Ov008MenuEntryDef data_ov008_02090598[];

void Ov008_DispatchFrom2DTable(int arg0, int index, int column)
{
    Ov008_GetMenuContext();
    Ov008_GetContext();
    Ov008_WidgetRef_Init(arg0, data_ov008_02090598[(short)index].aSub[column].nId);
}

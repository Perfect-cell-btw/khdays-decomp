/* ov019 .data pointer tables, 0x0207fd60-0x0207fd78.
 *
 * 1 table, all zero in the ROM image because every entry is a relocation;
 * a zero word is a null entry.
 */

typedef void (*Ov_Fn)(void);

extern void Ov019_RecordStatHighWater(void);
extern void Ov019_ShowMessageWithCounters(void);
extern void Ov019_PollMenuFlow(void);
extern void Ov019_StoreSlotIndex(void);
extern void Ov019_AdvancePlayTime(void);

Ov_Fn data_ov019_0207fd60[6] = {

    Ov019_RecordStatHighWater,

    0,

    Ov019_ShowMessageWithCounters,

    Ov019_PollMenuFlow,

    Ov019_StoreSlotIndex,

    Ov019_AdvancePlayTime,

};

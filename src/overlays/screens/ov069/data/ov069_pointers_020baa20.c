/* ov069 .data pointer tables, 0x020baa20-0x020baa70.
 *
 * 2 tables, all zero in the ROM image because every entry is a relocation;
 * a zero word is a null entry.
 */

extern void Ov069_IsItemFlagSet(void);
extern void Ov069_RequirementListMet(void);
extern void Ov069_ResourceGE_Arg3x2a4c(void);
extern void Ov069_CountActiveAndCompare(void);
extern void Ov069_ResourceGE(void);
extern void Ov069_ResourceGE_2(void);
extern void Ov069_ResourceGE_3(void);
extern void Ov069_IsFlagSetComplete(void);
extern void Ov069_ConstReturn1(void);
extern void Ov069_ResourceGE_4(void);
extern void Ov069_AreKeyFlagsComplete(void);
extern void Ov069_ItemStockAvailable(void);
extern void Ov069_ConstReturn1_2(void);
extern void Ov069_HasKind4MenuEntry(void);
extern void Ov069_ReportGlobalHalfword(void);
extern void Ov069_ReportGlobalHalfword_2(void);
extern int data_ov069_020ba7d0;
extern int data_ov069_020ba7d8;
extern int data_ov069_020ba7e2;

void *data_ov069_020baa20[3] = {

    &data_ov069_020ba7e2,

    &data_ov069_020ba7d8,

    &data_ov069_020ba7d0,

};

void *data_ov069_020baa2c[17] = {

    (void *)Ov069_IsItemFlagSet,

    (void *)Ov069_IsItemFlagSet,

    (void *)Ov069_RequirementListMet,

    (void *)Ov069_ResourceGE_Arg3x2a4c,

    (void *)Ov069_CountActiveAndCompare,

    (void *)Ov069_ResourceGE,

    (void *)Ov069_ResourceGE_2,

    (void *)Ov069_ResourceGE_3,

    (void *)Ov069_IsFlagSetComplete,

    (void *)Ov069_ConstReturn1,

    (void *)Ov069_ResourceGE_4,

    (void *)Ov069_AreKeyFlagsComplete,

    (void *)Ov069_ItemStockAvailable,

    (void *)Ov069_ConstReturn1_2,

    (void *)Ov069_HasKind4MenuEntry,

    (void *)Ov069_ReportGlobalHalfword,

    (void *)Ov069_ReportGlobalHalfword_2,

};

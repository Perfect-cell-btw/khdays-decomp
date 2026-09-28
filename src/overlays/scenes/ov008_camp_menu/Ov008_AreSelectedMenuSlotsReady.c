typedef unsigned char u8;
typedef unsigned int u32;

struct Ov008MenuSlot {
    u8 pad00[2];
    u8 padFlags : 2;
    u8 unavailable : 1;
    u8 padFlagsHi : 5;
    u8 state;
};

extern u32 Ov008_GetCachedPlayerMask(void);
extern int Ov008_IsBusy(void);
extern int Ov008_Link_IsLocal(void);
extern struct Ov008MenuSlot *Ov008_GetPlayerRecord(int slot);

int
Ov008_AreSelectedMenuSlotsReady(void)
{
    int slot;
    int selectedCount = 0;
    int readyCount = 0;
    u32 selectedMask = Ov008_GetCachedPlayerMask();

    if (Ov008_IsBusy() == 0) {
        return 0;
    }
    if (Ov008_Link_IsLocal() != 0) {
        return 1;
    }

    for (slot = 1; slot < 4; slot++) {
        struct Ov008MenuSlot *record = Ov008_GetPlayerRecord(slot);

        if ((selectedMask & (1 << slot)) != 0) {
            selectedCount++;
        }
        if (record->unavailable == 0 && record->state == 8) {
            readyCount++;
        }
    }

    if (selectedCount <= 0) {
        return 0;
    }
    return selectedCount == readyCount;
}

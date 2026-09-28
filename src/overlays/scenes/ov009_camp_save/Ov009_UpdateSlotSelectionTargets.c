/* Sets the slide targets of the two save panels for the current page. */

typedef unsigned char u8;

typedef struct Ov009SaveContext {
    u8 pad000[0x68];
    int pending;
} Ov009SaveContext;

typedef struct Ov009SlotReleaseConfig {
    int targetValue;
    int currentValue;
} Ov009SlotReleaseConfig;

extern const int data_ov009_02056008[2];
extern int Ov009_GetContext(void);
extern int Ov009_FindEntryById(int manager, int id);
extern int *Ov009_ApplyFirstValidSlot(int manager, int entry);
extern void Ov009_ReleaseTwoSlotsEx(
    int manager,
    int entry,
    Ov009SlotReleaseConfig *config
);

void Ov009_UpdateSlotSelectionTargets(Ov009SaveContext *ctx)
{
    Ov009SlotReleaseConfig config;
    unsigned int i;
    int manager = Ov009_GetContext();

    for (i = 0; i < 2; i++) {
        int entry;
        int id = data_ov009_02056008[i];
        entry = Ov009_FindEntryById(manager, id);
        int *slot = Ov009_ApplyFirstValidSlot(manager, entry);

        config.currentValue = slot[1];
        if (ctx->pending != 0) {
            if (id == 0x15) {
                config.targetValue = 0x28000;
            } else {
                config.targetValue = 0x88000;
            }
        } else {
            if (id == 0x15) {
                config.targetValue = 0x88000;
            } else {
                config.targetValue = 0x28000;
            }
        }
        Ov009_ReleaseTwoSlotsEx(manager, entry, &config);
    }
}

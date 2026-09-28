/* Slides the two page arrows in or out depending on the pending state. */

#include "nitro/types.h"

typedef struct Ov009SaveContext {
    u8 pad000[0x64];
    int pending;
} Ov009SaveContext;

typedef struct Ov009SlotReleaseConfig {
    int targetValue;
    int currentValue;
} Ov009SlotReleaseConfig;

extern const int data_ov025_020b4048[2];
extern int Ov025_GetContext(void);
extern int Ov025_FindEntryById(int manager, int id);
extern int *Ov025_ApplyFirstValidSlot(int manager, int entry);
extern void Ov025_ReleaseTwoSlotsEx(
    int manager,
    int entry,
    Ov009SlotReleaseConfig *config
);

void Ov025_SaveMenu_SlideArrows(Ov009SaveContext *ctx)
{
    Ov009SlotReleaseConfig config;
    unsigned int i;
    int manager = Ov025_GetContext();

    for (i = 0; i < 2; i++) {
        int entry;
        int id = data_ov025_020b4048[i];
        entry = Ov025_FindEntryById(manager, id);
        int *slot = Ov025_ApplyFirstValidSlot(manager, entry);

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
        Ov025_ReleaseTwoSlotsEx(manager, entry, &config);
    }
}

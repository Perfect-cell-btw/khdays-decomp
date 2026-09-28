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

extern const int data_ov008_0208f4e8[2];
extern int Ov008_GetContext(void);
extern int Ov008_FindEntryById(int manager, int id);
extern int *Ov008_GetEntryPos(int manager, int entry);
extern void Ov008_SetEntryPos(
    int manager,
    int entry,
    Ov009SlotReleaseConfig *config
);

void Ov008_SaveMenu_SlideArrows(Ov009SaveContext *ctx)
{
    Ov009SlotReleaseConfig config;
    unsigned int i;
    int manager = Ov008_GetContext();

    for (i = 0; i < 2; i++) {
        int entry;
        int id = data_ov008_0208f4e8[i];
        entry = Ov008_FindEntryById(manager, id);
        int *slot = Ov008_GetEntryPos(manager, entry);

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
        Ov008_SetEntryPos(manager, entry, &config);
    }
}

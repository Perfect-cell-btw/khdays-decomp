#include "nitro/types.h"

#include "game/ov008_camp_menu.h"
#include "game/engine.h"
#define MISSION_CONTEXT (data_ov008_02090f24.pContext)

void Ov008_MissionResolveDuplicateIds(void) {
    int i = 0;
    int j;
    MissionEntry *current = MISSION_CONTEXT->liveEntries.entries;
    MissionEntry *previous = MISSION_CONTEXT->sentEntries.entries;

    for (; i < 4; i++) {
        for (j = i + 1; j < 4; j++) {
            MissionEntry *left = &current[i];
            MissionEntry *right = &current[j];

            if (right->characterId == left->characterId && left->flags.selectable && right->flags.selectable &&
                (right->characterId != previous[j].characterId || left->characterId != previous[i].characterId)) {
                int changed;

                if (right->characterId != previous[j].characterId) {
                    changed = j;
                } else {
                    changed = i;
                }
                current[changed].characterId = previous[changed].characterId;
                current[changed].flags.request = 0;
            }
        }
    }

restart_duplicate_scan:
    for (i = 0; i < 4; i++) {
        for (j = i + 1; j < 4; j++) {
            if (current[j].characterId == current[i].characterId && current[i].flags.selectable &&
                current[j].flags.selectable) {
                current[j].characterId = RandNextScaled(12);
                current[j].flags.request = 0;
                goto restart_duplicate_scan;
            }
        }
    }

    MISSION_CONTEXT->sentEntries =
        MISSION_CONTEXT->liveEntries;
}

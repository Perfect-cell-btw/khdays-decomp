#include "nitro/types.h"

#include "game/ov006_mission_mode_select.h"

/* Resolves duplicate character ids among the four mission slots: a slot that just changed to
 * another slot's id reverts to its previous one, and any duplicates left get a random id; then
 * remembers the ids. */

extern int RandNextScaled(int bound);

void Ov006_MissionResolveDuplicateIds(void) {
    int i = 0;
    int j;
    MissionEntry *current = data_ov006_020565e4.pContext->liveEntries.entries;
    MissionEntry *previous = data_ov006_020565e4.pContext->sentEntries.entries;

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

    data_ov006_020565e4.pContext->sentEntries =
        data_ov006_020565e4.pContext->liveEntries;
}

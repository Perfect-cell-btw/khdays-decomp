/* Spawn step: hold off while the spawner is still busy (+0xad of its owner),
 * then pick the entry animation -- the short one when the "seen before" bit is
 * set, the full one otherwise -- and hand control to the idle handler. */

#include "game/ai_task.h"

extern void SetIndexedSlot(void *self, int script, void *handler);

typedef struct {
    char pad0000[0x1c7];
    unsigned char bEntryAnim;   /* +0x1c7 */
} Ov236Model;

typedef struct {
    char pad0000[0xad];
    unsigned char bBusy;        /* +0xad */
} Ov236Spawner;

typedef struct {
    Ov236Model *pModel;         /* +0 */
    Ov236Spawner *pSpawner;     /* +4 */
    char pad0008[0x4a];
    unsigned char bSeenBefore : 1;  /* +0x52 bit 0 */
} Ov236Actor;

typedef struct {
    AI_TASK_FIELDS(Ov236Actor)
} Ov236Enemy;

void Ov236_SpawnStep(Ov236Enemy *self) {
    Ov236Actor *actor = self->pState;

    if (actor->pSpawner->bBusy != 0) {
        return;
    }

    if (actor->bSeenBefore) {
        actor->pModel->bEntryAnim = 4;
    } else {
        actor->pModel->bEntryAnim = 7;
    }

    SetIndexedSlot(self, self->slot, 0);
}

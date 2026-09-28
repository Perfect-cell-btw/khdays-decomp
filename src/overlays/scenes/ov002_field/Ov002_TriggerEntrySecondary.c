/* When the entry's game-state field is set, runs its owner's secondary activation callback; returns
 * its result or 0. */

#include "nitro/types.h"

typedef struct Ov002Entry Ov002Entry;
typedef int (*Ov002EntryCallback)(Ov002Entry *entry);

typedef struct {
    unsigned char pad0000[0x24];
    Ov002EntryCallback pOnActive;
    Ov002EntryCallback pOnActiveSecondary;
} Ov002EntryOwner;

struct Ov002Entry {
    unsigned char pad0000[8];
    Ov002EntryOwner *pOwner;
    unsigned char pad000c[8];
    u16 wKey;
    u8 bKind;
};

extern int GameState_GetField(int key, int kind);

int Ov002_TriggerEntrySecondary(Ov002Entry *self)
{
    int eligible;

    if ((GameState_GetField(self->wKey, self->bKind) & 1) != 0) {
        eligible = 1;
    } else {
        eligible = 0;
    }

    if (eligible != 0 && self->pOwner->pOnActiveSecondary != 0) {
        return self->pOwner->pOnActiveSecondary(self);
    }

    return 0;
}

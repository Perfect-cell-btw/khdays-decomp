/* Freezes or unfreezes the party: toggles the flags, shows/hides the members and resets their
 * velocity. */

#include "nitro/types.h"

typedef struct VecFx32 {
    int x;
    int y;
    int z;
} VecFx32;

typedef struct SceneNode {
    unsigned int flags00;
    u16 flags04;
} SceneNode;

typedef struct Ov022ActorEntry {
    u64 flags00;
    char padding008[0x18];
    SceneNode *sceneNode20;
    char padding024[4];
    VecFx32 position28;
} Ov022ActorEntry;

typedef struct Ov022EntryRoot {
    unsigned int flags00;
    char padding004[0x30];
    u8 entryCount34;
} Ov022EntryRoot;

typedef struct Ov022EntrySystem {
    int field00;
    Ov022EntryRoot *root04;
} Ov022EntrySystem;

extern Ov022EntrySystem data_ov022_020b2e78;
extern u8 data_0204c240;
extern VecFx32 data_02041dc8;

extern Ov022ActorEntry *GetEntryField20ByIndex(int index);
extern void SceneNode_Enable(u16 *nodeFlags);
extern void SceneNode_Disable(u16 *nodeFlags);

void Ov022_Party_SetFrozen(int enable)
{
    int index;
    Ov022ActorEntry *entry;
    int defaultX;
    int defaultZ;
    Ov022EntryRoot *root;

    root = data_ov022_020b2e78.root04;

    if (root == 0) {
        return;
    }

    if (enable != 0) {
        root->flags00 |= 1;
    } else {
        root->flags00 &= ~1;
    }

    if ((data_0204c240 & 4) != 0) {
        return;
    }

    index = 0;
    if (0 < (int)root->entryCount34) {
        defaultX = data_02041dc8.x;
        defaultZ = data_02041dc8.z;

        do {
            entry = GetEntryField20ByIndex(index);

            if (enable != 0) {
                root->flags00 |= 4;
                entry->flags00 |= 0x80;
                if ((entry->sceneNode20->flags00 & 0x20) == 0) {
                    SceneNode_Enable(&entry->sceneNode20->flags04);
                }
                entry->position28.x = defaultX;
                entry->position28.y = 0;
                entry->position28.z = defaultZ;
            } else {
                root->flags00 &= ~4;
                entry->flags00 &= ~0x80ULL;
                if ((entry->flags00 & 0x0002000000000000ULL) == 0 &&
                    (entry->sceneNode20->flags00 & 0x20) == 0) {
                    SceneNode_Disable(&entry->sceneNode20->flags04);
                }
            }
            index++;
        } while (index < root->entryCount34);
    }
}

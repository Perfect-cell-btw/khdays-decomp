/* Registry task (0x64) recording owner, id, kind, enabled and node; spawns the slot (Slot_Spawn)
 * when the owner's flag bit 0 at +0x40 is set. */

#include "nitro/types.h"

typedef struct {
    int owner;
    short id;
    u8 kind;
    u8 pad;
    int enabled;
    void *node;
    u32 field_10;
} Ov107Sub;

extern void *func_ov107_020c9848(void);
extern int CreateRegistryEntry(int param_1, unsigned int param_2, unsigned int param_3, int param_4, int param_5, int *param_6);
extern int Ov107_SpawnTaskTeardown(int param_1);
extern void Ov107_Reaction_BranchByOwnerBit0(int self);
extern unsigned int Slot_Spawn(unsigned int param_1, unsigned int param_2, unsigned int *param_3, unsigned int param_4);

int Ov107_CreateSpawnTask(int self, int id, int kind, int enabled, void *node) {
    int base = *(int *)func_ov107_020c9848();
    Ov107Sub *sub;
    int handle = CreateRegistryEntry(*(int *)(base + 0x3c), 0x64, 0x14,
                                (int)Ov107_Reaction_BranchByOwnerBit0, (int)Ov107_SpawnTaskTeardown,
                                (int *)&sub);
    sub->owner = self;
    sub->id = (short)id;
    sub->kind = (u8)kind;
    sub->enabled = enabled;
    sub->node = node;
    if ((*(int *)(sub->owner + 0x40) << 31) >> 31) {
        sub->field_10 = Slot_Spawn((unsigned int)sub->id, sub->kind,
                                       (u32 *)((char *)sub->node + 0x10), 0);
    }
    return handle;
}

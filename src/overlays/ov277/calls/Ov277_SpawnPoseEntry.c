/* Spawn a size-0xc registry entry (CreateRegistryEntry, cbs cf098/cf134) into *entry, then link it:
 * entry[0]=self, entry[1]=the given owner, and copy the self's +0x3b8 item's pose (+4) into the
 * owner's +4. */
struct blk11 { int w[11]; };
struct Ov244Clip { int pad0; struct blk11 pose; };
extern int CreateRegistryEntry(int list, int a, int b, void *cb2, void *cb1, int **out);
extern void Ov277_TaskTeardown_FlagPart_2(void);
extern void Ov277_ResetChannelsB(void);
int Ov277_SpawnPoseEntry(int param_1, int owner) {
    int *entry;
    int spawn = CreateRegistryEntry(*(int *)(param_1 + 0x3c), 100, 0xc,
                              &Ov277_ResetChannelsB, &Ov277_TaskTeardown_FlagPart_2, &entry);
    entry[0] = param_1;
    entry[1] = owner;
    ((struct Ov244Clip *)entry[1])->pose = ((struct Ov244Clip *)*(int *)(entry[0] + 0x3b8))->pose;
    return spawn;
}

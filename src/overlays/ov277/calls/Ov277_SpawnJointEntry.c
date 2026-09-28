/* Spawn a size-0x24 registry entry (CreateRegistryEntry, cbs cf538/cf620) into *entry linking the
 * actor (entry[1]) and the given owner (entry[0]); when the actor's +0x50 kind is 1 the owner
 * gets the "DM002" joint handle (0203bdfc) at entry[3], the cf16c handler at +0x74 and a
 * back-link to the entry at +0x84. */
extern int CreateRegistryEntry(int list, int a, int b, void *cb2, void *cb1, int **out);
extern int FindResourceIndexByName(int owner, const char *name);
extern void Ov277_TaskTeardown_FlagOwner_3(void);
extern void Ov277_EnterPounceHold(void);
extern void Ov277_ArmSwingSweepB(void);
extern const char data_ov277_020d3840[];

int Ov277_SpawnJointEntry(int actor, int owner) {
    int *entry;
    int spawn = CreateRegistryEntry(*(int *)(actor + 0x3c), 100, 0x24,
                              &Ov277_EnterPounceHold, &Ov277_TaskTeardown_FlagOwner_3, &entry);
    entry[1] = actor;
    entry[0] = owner;
    if (*(int *)(entry[1] + 0x50) == 1) {
        entry[3] = FindResourceIndexByName(entry[0], data_ov277_020d3840);
        *(void **)(entry[0] + 0x74) = (void *)&Ov277_ArmSwingSweepB;
        *(int **)(entry[0] + 0x84) = entry;
    }
    return spawn;
}

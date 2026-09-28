/* Create the ov237 actor's brain: a 0x6c-byte state node (0203c5c0 on the +0x3c model, start
 * 020cd4bc, teardown 020cd550) holding the actor, its +0x384 rig and +0x3ac item; a linked partner
 * (+0x4ac set) is told mode 2 (020c5c14 on +0x4a4). The node becomes +0x214. */
extern void CreateRegistryEntry(int model, int a, int size, void *start, void *end, int **out);
extern void Ov107_SetStatusAndEmit(int actor, int mode);
extern void Ov237_BrainStart(void);
extern void Ov237_BrainReleaseNoOp(void);

void Ov237_CreateBrain(char *self)
{
    int *state;

    CreateRegistryEntry(*(int *)(self + 0x3c), 100, 0x6c, Ov237_BrainStart, Ov237_BrainReleaseNoOp, &state);
    state[0] = (int)self;
    state[1] = *(int *)(state[0] + 0x384);
    state[2] = *(int *)(state[0] + 0x3ac);
    if (*(int *)(state[0] + 0x4ac) != 0) {
        Ov107_SetStatusAndEmit(*(int *)(state[0] + 0x4a4), 2);
    }
    *(int **)(self + 0x214) = state;
}

/* Allocate the size-0xc render instance for this actor (kind 0x64, handler 020d192c),
 * seed it with the value at (param_1)+0x394 and return it. */
extern int CreateRegistryEntry(int a, int b, int c, void *handler, int e, void *out);
extern void Ov212_Reaction_ResetChannelsAndDispatch(int);
int Ov212_CreateReactionTask(int param_1) {
    int *out;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 0x64, 0xc, (void *)&Ov212_Reaction_ResetChannelsAndDispatch, 0, &out);
    *out = *(int *)(param_1 + 0x394);
    return (int)out;
}

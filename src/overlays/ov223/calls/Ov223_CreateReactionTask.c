/* Spawns the child object through CreateRegistryEntry (callback Ov223_Reaction_ResetChannelsAndDispatch, class 0x64,
 * size 0xc), seeds its first word from +0x394 of the owner and returns it.
 *
 * CreateRegistryEntry takes SIX arguments: the last two (the flag and the out-pointer) ride on
 * the stack, and the out slot is the third word of the frame. */
extern void *CreateRegistryEntry(int a, int b, int c, void *cb, int flag, void **out);
extern void Ov223_Reaction_ResetChannelsAndDispatch(int);

void *Ov223_CreateReactionTask(char *self) {
    void *out;
    CreateRegistryEntry(*(int *)(self + 0x3c), 0x64, 0xc, (void *)Ov223_Reaction_ResetChannelsAndDispatch, 0, &out);
    *(int *)out = *(int *)(self + 0x394);
    return out;
}

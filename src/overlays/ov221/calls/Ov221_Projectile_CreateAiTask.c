/* Allocate the size-0x68 render instance for this actor (kind 0x64, handler 020cc9a8),
 * back-link it to the actor, cache the actor's render root (+0x384) at +4, and store the
 * instance at (param_1)+0x214. */
extern int CreateRegistryEntry(int a, int b, int c, void *handler, int e, void *out);
extern void Ov221_stateInitClearSlots(void);
void Ov221_Projectile_CreateAiTask(int param_1) {
    int *out;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 0x64, 0x68, (void *)&Ov221_stateInitClearSlots, 0, &out);
    *out = param_1;
    out[1] = *(int *)(*out + 0x384);
    *(int *)(param_1 + 0x214) = (int)out;
}

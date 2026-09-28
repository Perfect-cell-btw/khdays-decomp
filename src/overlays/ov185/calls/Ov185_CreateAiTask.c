/* Allocate the size-0x70 render instance for this actor (kind 0x64, handler 020ce738),
 * back-link it to the actor and store it at (param_1)+0x214. */
extern int CreateRegistryEntry(int a, int b, int c, void *handler, int e, void *out);
extern void Ov185_SeedVecAndArm(void);
void Ov185_CreateAiTask(int param_1) {
    int *out;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 0x64, 0x70, (void *)&Ov185_SeedVecAndArm, 0, &out);
    *out = param_1;
    *(int *)(param_1 + 0x214) = (int)out;
}

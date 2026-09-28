/* Allocate the size-0x78 render instance for this actor (kind 0x64, handler 020cd2ac),
 * back-link it to the actor and store it at (param_1)+0x214. */
extern int CreateRegistryEntry(int a, int b, int c, void *handler, int e, void *out);
extern void Ov273_InitActionState(void);
void Ov273_CreateAiTask(int param_1) {
    int *out;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 0x64, 0x78, (void *)&Ov273_InitActionState, 0, &out);
    *out = param_1;
    *(int *)(param_1 + 0x214) = (int)out;
}

/* Allocate the size-0x80 render instance for this actor (kind 0x64, handler 020cca50),
 * back-link it to the actor and store it at (param_1)+0x214. */
extern int CreateRegistryEntry(int a, int b, int c, void *handler, int e, void *out);
extern void Ov125_InitChase(void);
void Ov125_CreateAiTask(int param_1) {
    int *out;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 0x64, 0x80, (void *)&Ov125_InitChase, 0, &out);
    *out = param_1;
    *(int *)(param_1 + 0x214) = (int)out;
}

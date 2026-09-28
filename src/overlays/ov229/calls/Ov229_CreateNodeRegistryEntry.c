/* Create a sub-object via CreateRegistryEntry (kind 0x64/0x6c), back-link it, copy owner
 * state at +0x384, and store it at +0x214. */
extern int CreateRegistryEntry(int a, int b, int c, void *handler, int e, int *out);
extern void Ov229_BeginPhasedReaction(void);
void Ov229_CreateNodeRegistryEntry(int param_1) {
    int obj;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 0x64, 0x6c, (void *)&Ov229_BeginPhasedReaction, 0, &obj);
    *(int *)obj = param_1;
    *(int *)(obj + 4) = *(int *)(*(int *)obj + 0x3a8);
    *(int *)(param_1 + 0x214) = obj;
}

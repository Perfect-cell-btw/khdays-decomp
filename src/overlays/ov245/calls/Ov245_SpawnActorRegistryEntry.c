/* Create a sub-object via CreateRegistryEntry (kind 0x64/0x48, handler Ov245_NodeInit2),
 * back-link it, copy owner state at +0x384, and store it at +0x214. */
extern int CreateRegistryEntry(int a, int b, int c, void *handler, int e, int *out);
extern void Ov245_NodeInit2(void);
void Ov245_SpawnActorRegistryEntry(int param_1) {
    int obj;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 0x64, 0x48, (void *)&Ov245_NodeInit2, 0, &obj);
    *(int *)obj = param_1;
    *(int *)(obj + 4) = *(int *)(*(int *)obj + 0x384);
    *(int *)(param_1 + 0x214) = obj;
}

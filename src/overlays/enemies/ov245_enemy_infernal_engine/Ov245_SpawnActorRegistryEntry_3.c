/* Spawn a child object via CreateRegistryEntry (+0x384 copy), link back to owner, store at +0x214. */
extern int CreateRegistryEntry(int a, int b, int c, void *cb, int flag, int *out);
extern void Ov245_Mounted_AiStateInit(int);
void Ov245_SpawnActorRegistryEntry_3(int param_1) {
    int obj;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 0x64, 0x14, (void *)&Ov245_Mounted_AiStateInit, 0, &obj);
    *(int *)obj = param_1;
    *(int *)(obj + 4) = *(int *)(*(int *)obj + 0x384);
    *(int *)(param_1 + 0x214) = obj;
}

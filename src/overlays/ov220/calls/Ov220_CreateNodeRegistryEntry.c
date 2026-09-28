extern void CreateRegistryEntry(void *ctx, int a, int b, void *callback, int zero, void *out);
extern void Ov220_AiStateInit(void);

void Ov220_CreateNodeRegistryEntry(void *obj)
{
    void **node;

    CreateRegistryEntry(*(void **)((char *)obj + 0x3c), 0x64, 0x64, Ov220_AiStateInit, 0, &node);
    node[0] = obj;
    node[1] = *(void **)((char *)node[0] + 0x384);
    *(void **)((char *)obj + 0x214) = node;
}

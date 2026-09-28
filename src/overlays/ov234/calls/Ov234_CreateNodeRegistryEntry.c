extern void CreateRegistryEntry(void *ctx, int a, int b, void *callback, int zero, void *out);
extern void Ov234_EnterRecoilState(void);

void Ov234_CreateNodeRegistryEntry(void *obj)
{
    void **node;

    CreateRegistryEntry(*(void **)((char *)obj + 0x3c), 0x64, 0x74, Ov234_EnterRecoilState, 0, &node);
    node[0] = obj;
    node[1] = *(void **)((char *)node[0] + 0x384);
    *(void **)((char *)obj + 0x214) = node;
}

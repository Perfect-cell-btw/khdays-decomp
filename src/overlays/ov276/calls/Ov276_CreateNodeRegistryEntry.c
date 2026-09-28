extern void CreateRegistryEntry(void *ctx, int a, int b, void *callback, int zero, void *out);
extern void Ov276_BeginPhasedReaction(void);

void Ov276_CreateNodeRegistryEntry(void *obj)
{
    void **node;

    CreateRegistryEntry(*(void **)((char *)obj + 0x3c), 0x64, 0x6c, Ov276_BeginPhasedReaction, 0, &node);
    node[0] = obj;
    node[1] = *(void **)((char *)node[0] + 0x3a8);
    *(void **)((char *)obj + 0x214) = node;
}

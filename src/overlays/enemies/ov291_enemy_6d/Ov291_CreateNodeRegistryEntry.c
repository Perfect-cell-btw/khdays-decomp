/* Creates the actor's AI registry entry (noting mode 4) and links it. */

extern unsigned char data_0204c240[];
extern void CreateRegistryEntry(void *ctx, int a, int b, void *callback, int zero, void *out);
extern void Ov291_AiStateInit(void);

void Ov291_CreateNodeRegistryEntry(void *obj)
{
    int *node;

    CreateRegistryEntry(*(void **)((char *)obj + 0x3c), 0x64, 0x38, Ov291_AiStateInit, 0, &node);
    node[0xc] = (data_0204c240[0] & 4) != 0;
    *(void **)node = obj;
    *(int **)((char *)obj + 0x214) = node;
}

/* Spawn a child object via CreateRegistryEntry (+0x388 copy), link back to owner, store at +0x214.
 */

extern void CreateRegistryEntry(void *ctx, int a, int b, void *callback, int zero, void *out);
extern void Ov239_AiStateInit(void);

void Ov239_CreateNodeRegistryEntry(void *obj)
{
    void **node;

    CreateRegistryEntry(*(void **)((char *)obj + 0x3c), 0x64, 0x38, Ov239_AiStateInit, 0, &node);
    node[0] = obj;
    node[1] = *(void **)((char *)node[0] + 0x388);
    *(void **)((char *)obj + 0x214) = node;
}

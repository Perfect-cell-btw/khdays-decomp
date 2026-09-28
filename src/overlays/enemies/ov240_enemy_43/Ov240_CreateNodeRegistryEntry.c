/* Creates the object's state-machine registry entry (starting in its AI init state), links it to
 * the object and its model (+0x384) and stores it at +0x214. */

extern void CreateRegistryEntry(void *ctx, int a, int b, void *callback, int zero, void *out);
extern void Ov240_AiStateInit(void);

void Ov240_CreateNodeRegistryEntry(void *obj)
{
    void **node;

    CreateRegistryEntry(*(void **)((char *)obj + 0x3c), 0x64, 0x44, Ov240_AiStateInit, 0, &node);
    node[0] = obj;
    node[1] = *(void **)((char *)node[0] + 0x388);
    *(void **)((char *)obj + 0x214) = node;
}

/* Creates the object's state-machine registry entry (starting in its init state), links it to the
 * object and to the object's model (+0x9c) and stores it at +0x214. */

extern void CreateRegistryEntry(int a, int b, int c, void *cb, int d, void *out);
extern void Ov123_stateInitClearSlots(void);

void Ov123_CreateNodeRegistryEntry(int *node) {
    int *obj;
    CreateRegistryEntry(node[0xf], 100, 0x38, Ov123_stateInitClearSlots, 0, &obj);
    obj[0] = (int)node;
    obj[1] = *(int *)(*obj + 0x9c);
    node[0x85] = (int)obj;
}

extern void CreateRegistryEntry(int a, int b, int c, void *cb, int d, void *out);
extern void Ov171_stateInitClearSlots(void);

void Ov171_CreateNodeRegistryEntry(int *node) {
    int *obj;
    CreateRegistryEntry(node[0xf], 100, 0x50, Ov171_stateInitClearSlots, 0, &obj);
    obj[0] = (int)node;
    obj[1] = *(int *)(*obj + 0x9c);
    node[0x85] = (int)obj;
}

/* Allocate and seed a 0x1c-byte task node: two id bytes at +0x14/+0x15, the
 * payload at +0x18 and the caller word at +0xc, with the default step handler in
 * the first callback slot and the other two empty.
 *
 * The slot setter's guard is an INT comparison against -1, not a pointer one --
 * see Ov002_CreateTaskNodeWW. */
extern void *NNSi_FndAllocFromDefaultExpHeap(unsigned int size);
extern void Ov002_NodeTallyPhase(void);

static inline void set_callback(void **slot, void *value) {
    if ((int)value != -1) {
        *slot = value;
    }
}

void *Ov002_CreateTaskNodeBB(int idA, int idB, int payload, int extra) {
    char *node = (char *)NNSi_FndAllocFromDefaultExpHeap(0x1c);

    node[0x14] = (char)idA;
    node[0x15] = (char)idB;
    *(int *)(node + 0x18) = payload;
    *(int *)(node + 0xc) = extra;

    set_callback((void **)(node + 0), (void *)Ov002_NodeTallyPhase);
    set_callback((void **)(node + 4), (void *)0);
    set_callback((void **)(node + 8), (void *)0);

    return node;
}

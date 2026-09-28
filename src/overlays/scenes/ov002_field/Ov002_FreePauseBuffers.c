/* Release every buffer the pause block owns: ten slots from +0x8cbc, each freed
 * and cleared. The pre-pass at Ov002_DestroyPauseObject detaches whatever still
 * points at them. */
extern void Ov002_DestroyPauseObject(void);
extern void NNSi_FndFreeFromDefaultHeap(void *block);

typedef struct {
    char pad0000[0x28];
    void *slots[10];        /* +0x28 of the block, i.e. +0x8cbc */
} Ov002PauseBlock;

typedef struct {
    char pad0000[0x8c94];
    Ov002PauseBlock pause;  /* +0x8c94 */
} Ov002RootContext;

extern Ov002RootContext *data_ov002_0207fa00;

void Ov002_FreePauseBuffers(void) {
    Ov002PauseBlock *block = &data_ov002_0207fa00->pause;
    int i;

    Ov002_DestroyPauseObject();

    for (i = 0; i < 10; i++) {
        if (block->slots[i] != 0) {
            NNSi_FndFreeFromDefaultHeap(block->slots[i]);
            block->slots[i] = 0;
        }
    }
}

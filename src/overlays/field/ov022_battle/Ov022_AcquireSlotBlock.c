/* Register the frame callback the first time anyone asks, count the reference,
 * and hand back a cleared six-word slot block. */
extern void StoreGlobalPtrArray4At0c(int channel, void *handler);
extern void Ov022_ApplyControlTable(void);

extern int data_ov022_020b2eac;

void Ov022_AcquireSlotBlock(int *slots) {
    int i;

    if (data_ov022_020b2eac == 0) {
        StoreGlobalPtrArray4At0c(0xa, (void *)Ov022_ApplyControlTable);
    }

    data_ov022_020b2eac++;

    for (i = 0; i < 6; i++) {
        *slots++ = 0;
    }
}

/* Take a 0x30-byte channel block: register the frame callback on channel 9 the
 * first time anyone asks, count the reference, clear the block and stamp the two
 * caller words at +0 / +4. */
extern void StoreGlobalPtrArray4At0c(int channel, void *handler);
extern void Ov022_RunShotCommand(void);
extern void MIi_CpuClearFast(unsigned int value, void *dest, unsigned int size);

extern int data_ov022_020b2ea8;

void Ov022_TakeChannelBlock(char *block, int a, int b) {
    if (data_ov022_020b2ea8 == 0) {
        StoreGlobalPtrArray4At0c(9, (void *)Ov022_RunShotCommand);
    }

    data_ov022_020b2ea8++;

    MIi_CpuClearFast(0, block, 0x30);

    *(int *)block = a;
    *(int *)(block + 4) = b;
}

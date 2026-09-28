/* Reset the four 0x30-byte decoder slots at the root heap and clear the active
 * pointer. */
extern void *NNSi_FndGetCurrentRootHeap(void);
extern void Ov002_FreeBufferAndClearStatus(void *slot);

typedef struct {
    char bytes[0x30];
} Ov022DecoderSlot;

extern void *data_ov022_020b2e74;

void Ov022_ResetDecoderSlots(void) {
    Ov022DecoderSlot *slots = (Ov022DecoderSlot *)NNSi_FndGetCurrentRootHeap();
    int i;

    for (i = 0; i < 4; i++) {
        Ov002_FreeBufferAndClearStatus(&slots[i]);
    }

    data_ov022_020b2e74 = 0;
}

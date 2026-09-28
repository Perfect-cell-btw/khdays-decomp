/* Move dispatcher of an ov259 helper: when a move is pending (+0x1c7 != -1) the +0x38c shape hides,
 * the move becomes current (+0x1c6) and its entry takes over (0 dock 020d2108, 1 020d21ac,
 * 2 020d2288, 3 latch 020d2328, 4 020d2658); the pending slot then clears. */
typedef struct { unsigned f : 8; } B8;

extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov259_HelperDockEntry(void);
extern void Ov259_ReleaseEntry(void);
extern void Ov259_Helper_AiEnterFlight(void);
extern void Ov259_HelperLatchEntry(void);
extern void Ov259_HelperReleaseEntry(void);

void Ov259_HelperDispatchMove(int *node)
{
    int *state = (int *)node[1];

    if (*(signed char *)(*state + 0x1c7) != -1) {
        ((B8 *)(*(int *)(*state + 0x38c) + 8))->f &= ~1;
        *(signed char *)(*state + 0x1c6) = *(signed char *)(*state + 0x1c7);
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0:
            SetIndexedSlot(node, 1, Ov259_HelperDockEntry);
            break;
        case 1:
            SetIndexedSlot(node, 1, Ov259_ReleaseEntry);
            break;
        case 2:
            SetIndexedSlot(node, 1, Ov259_Helper_AiEnterFlight);
            break;
        case 3:
            SetIndexedSlot(node, 1, Ov259_HelperLatchEntry);
            break;
        case 4:
            SetIndexedSlot(node, 1, Ov259_HelperReleaseEntry);
            break;
        }
    }
    *(signed char *)(*state + 0x1c7) = -1;
}

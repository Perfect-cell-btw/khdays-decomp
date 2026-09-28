/* Builds the lock-on selection for a slot when input is allowed: collects the actor's candidates
 * within the scan distance (larger with ability 0x55) and encodes the result; returns whether one
 * was found. */

typedef signed int s32;
typedef signed long long s64;
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Ov022SelectionResult {
    u32 selectionFlags00;
    s32 type04;
    void *candidate08;
    void *comparison0c;
    u32 field10;
    void *source14;
    void *actor18;
    s32 scanDistance1c;
    s32 selectedIndex20;
    s32 selectedValue24;
} Ov022SelectionResult;

extern int func_ov022_020881d8(void);
extern int Ov022_IsInputAllowedForActiveSlot(void);
extern int Slot_EvalPackedParam(int slot, int parameter);
extern int Ov022_CollectActorCandidates(u32 *selectionFlags, int slot);
extern void Ov022_EncodeSelectionResult(u8 *output, Ov022SelectionResult *selection);

int Ov022_BuildSlotSelection(u8 *output, int slot)
{
    Ov022SelectionResult selection;

    if (func_ov022_020881d8() != 0 ||
        Ov022_IsInputAllowedForActiveSlot() != 0) {
        return 0;
    }

    selection.scanDistance1c = 0x9000;
    selection.selectedIndex20 = -1;
    selection.selectedValue24 = 0;
    if (Slot_EvalPackedParam(slot, 0x55) != 0) {
        selection.scanDistance1c =
            (s32)(((s64)selection.scanDistance1c * 0x1800 + 0x800) >> 12);
    }

    if (Ov022_CollectActorCandidates(&selection.selectionFlags00, slot) == 0) {
        output[0] = 0;
        return 0;
    }

    Ov022_EncodeSelectionResult(output, &selection);
    return 1;
}

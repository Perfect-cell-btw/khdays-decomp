/* Moves a title menu selection up or down with wrap-around (the counts depend on the unlocked
 * options), playing the move sound. */

#include "nitro/types.h"

typedef struct {
    int values[3];
} OverlayCountTable;

typedef struct {
    u8 pad_0000[0x4c53];
    u8 second_locked;
    int first_extended;
} OverlayContext;

extern const OverlayCountTable data_ov000_0205a6b0;
extern OverlayContext *NNSi_FndGetCurrentRootHeap(void);
extern unsigned short Mem_ReadU16(void *input);
extern void PlaySound(int first, int second);

int Ov000_StepMenuSelection(void *input, int selection, int group) {
    OverlayCountTable counts = data_ov000_0205a6b0;
    int decrement = 0;
    int increment = 0;

    if (NNSi_FndGetCurrentRootHeap()->first_extended != 0) {
        counts.values[0] = 3;
    }
    if (NNSi_FndGetCurrentRootHeap()->second_locked == 0) {
        counts.values[1] = 1;
    }

    if ((Mem_ReadU16(input) & 0x40) != 0) {
        decrement = 1;
    }
    if ((Mem_ReadU16(input) & 0x80) != 0) {
        increment = 1;
    }
    Mem_ReadU16(input);
    Mem_ReadU16(input);

    if ((decrement != 0 || increment != 0) && counts.values[group] > 1) {
        PlaySound(0, 0);
    }
    if (decrement != 0) {
        selection--;
    }
    if (increment != 0) {
        selection++;
    }
    if (selection < 0) {
        selection = counts.values[group] - 1;
    }
    if (selection >= counts.values[group]) {
        selection = 0;
    }
    return selection;
}

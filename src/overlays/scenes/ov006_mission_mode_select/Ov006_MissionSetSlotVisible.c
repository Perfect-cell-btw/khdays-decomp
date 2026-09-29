/* Ov006_MissionSetSlotVisible -- Mission Mode: show or hide the currently selected 3D draw slot.
 * The slot index lives at OBJ+0x96dc (negative = none) and the 0x8c-byte slot array starts
 * at OBJ+0x4b08; bit 2 of a slot's first word is its visible flag. The slot is registered
 * with or removed from the renderer list at OBJ+0x4a8c either way. */

#include "game/engine.h"

extern void Slot_ClearFlagBit1(int list, int idx);
extern int *data_ov006_02056664;

struct Ov006DrawSlot {
    unsigned pad0 : 2;
    unsigned visible : 1;
    unsigned pad1 : 29;
    char rest[0x88];
};

void Ov006_MissionSetSlotVisible(int on) {
    int idx = *(int *)((char *)data_ov006_02056664 + 0x96dc);
    if (idx >= 0) {
        struct Ov006DrawSlot *slots =
            (struct Ov006DrawSlot *)((char *)data_ov006_02056664 + 0x4b08);
        slots[idx].visible = on != 0;
    }
    if (on != 0) {
        Slot_SetFlagBit1((int)((char *)data_ov006_02056664 + 0x4a8c),
                      *(int *)((char *)data_ov006_02056664 + 0x96dc));
        return;
    }
    Slot_ClearFlagBit1((int)((char *)data_ov006_02056664 + 0x4a8c),
                  *(int *)((char *)data_ov006_02056664 + 0x96dc));
}

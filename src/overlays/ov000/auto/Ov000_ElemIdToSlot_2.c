/* Ov000_ElemIdToSlot_2 -- map logo element id (0x18..0x1b) to a 0..3 slot index,
 * ov000 (dense switch / jump table). Returns -1 otherwise. */
int Ov000_ElemIdToSlot_2(int id) {
    int slot = -1;
    switch (id) {
    case 0x18: slot = 0; break;
    case 0x19: slot = 1; break;
    case 0x1a: slot = 2; break;
    case 0x1b: slot = 3; break;
    }
    return slot;
}

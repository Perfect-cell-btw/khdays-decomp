/* ★ CallVirtSlot1 takes TWO arguments; this file declared one. The dropped 0 is the ROM's
 * `mov r1, #0` at +0x00, shared with the two field stores. (2026-07-17)
 *
 */

extern void CallVirtSlot1(int p, int b);

void Ov012_ArmAndStart(int p) {
    *(int *)(p + 0x6c) = 0;
    *(int *)(p + 0x5c) = 0;
    *(int *)(p + 0x50) = 1;
    CallVirtSlot1(p, 0);
}

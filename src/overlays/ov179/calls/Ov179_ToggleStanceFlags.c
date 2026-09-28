/* Flip the stance flags: drop bit 0 of the hw60 high byte and then set 0x82 in it, and hand off.
 *
 * Matched byte-exact 2026-07-23, first compile. The AND is the `hi &= ~K` bitfield (it carries
 * the ROM's 16-bit truncation) and the OR is the explicit shift expression (it does not).
 *
 * One of three byte-identical siblings. */
extern void SetIndexedSlot(void *node, int idx, void *cb);
extern void Ov179_AiStep_QueueAction1IfActive(void);

struct hw60 { unsigned short lo : 8, hi : 8; };

void Ov179_ToggleStanceFlags(int *node) {
    int *state = (int *)node[1];

    ((struct hw60 *)(state[0] + 0x60))->hi &= ~1;
    {
        unsigned short hw60 = *(unsigned short *)(state[0] + 0x60);
        *(unsigned short *)(state[0] + 0x60) =
            (hw60 & ~0xff00) | (((((unsigned int)hw60 << 0x10) >> 0x18 | 0x82) << 0x18) >> 0x10);
    }
    SetIndexedSlot(node, *(signed char *)((int)node + 0x20), Ov179_AiStep_QueueAction1IfActive);
}

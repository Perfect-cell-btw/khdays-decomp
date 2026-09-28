/* Rebind the emitter's five slots to the current source.
 *
 * For each slot: if it still holds a handle, release it (NNS_G3dRenderObjRemoveAnmObj) and clear the
 * slot; then rebind unconditionally -- the `beq` skips only the release and the clear,
 * not the two calls that follow.
 *
 * PARKED behind three externs declared with EMPTY parentheses, which is the absence of
 * a prototype rather than a declaration of one, so nothing checked the calls:
 *   - NNS_G3dRenderObjRemoveAnmObj takes (base, item); the park passed only the base.  The ROM's
 *     `ldr r1,[r0,#0xc]` before the `cmp` is still live at the `bl`.
 *   - BindAnimTrack and Anim_SetFrameWrapped take the slot index as UNSIGNED SHORT.  That is
 *     the `lsl #0x10 ; lsr #0x10` pair in the ROM and it is worth 8 bytes; passing an
 *     int leaves the function short and looks like a codegen difference.
 * The correct prototypes were already written down in ov038's parked file next door.
 */
extern void Anim_SetFrameWrapped(void *p, unsigned short i, int z);
extern void NNS_G3dRenderObjRemoveAnmObj(void *base, int item);
extern void BindAnimTrack(void *p, unsigned short i, int a, short m);

void Ov044_RebindEmitterSlots(int r0, int r1) {
    int i;
    for (i = 0; i < 5; i++) {
        if (((int *)r0)[i + 3] != 0) {
            NNS_G3dRenderObjRemoveAnmObj((void *)(r0 + 0x20), ((int *)r0)[i + 3]);
            ((int *)r0)[i + 3] = 0;
        }
        BindAnimTrack((void *)r0, i, r0 + 0x108, (short)r1);
        Anim_SetFrameWrapped((void *)r0, i, 0);
    }
}

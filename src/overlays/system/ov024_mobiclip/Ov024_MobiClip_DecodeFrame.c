/* Ov024_MobiClip_DecodeFrame -- MobiClip: decode one frame and advance the six plane cursors.
 * Bails out while the read position (+0x9c) is still past the write position (+0xa0). A 0x8000 tag
 * on the frame's first halfword sets the "extended" flag (+0xa4). The decoder -- the payload
 * copied to ITCM, called through +0x38 with the decoder state at +0x34 (portable version:
 * libs/mobiclip/video/portable/mobiclip_frame_core.cpp) -- returns the bytes the frame used, and
 * the bitstream pointer advances by that, plus 4 for a tagged frame of an N3 stream. The frame's
 * quantizer (+0x3b4 of the decoder state) is recorded in the ring at +0x64 at cursor 0, both
 * scratch words are cleared, and each of the six cursors at +0xac wraps at the ring length (+0xa8).
 *
 * The cursor loop indexes the WHOLE object and folds the field offset into the index --
 * `((int *)ctx)[i + 0x2b]`, where 0xac / 4 = 0x2b. That is what keeps the ROM's
 * `add r3, ctx, i lsl #2 ; ldr r1,[r3,#0xac]`; `((int *)(ctx + 0xac))[i]` hoists the base instead,
 * and the two byte-offset forms become running pointers.
 */

int Ov024_MobiClip_DecodeFrame(int ctx) {
    int extra;
    int i;

    if ((unsigned int)*(int *)(ctx + 0x9c) > (unsigned int)*(int *)(ctx + 0xa0)) {
        return 0;
    }

    if ((*(unsigned short *)**(int **)(ctx + 0x34) & 0x8000) != 0) {
        *(int *)(ctx + 0xa4) = 1;
        extra = 4;
    } else {
        extra = 0;
        *(int *)(ctx + 0xa4) = 0;
    }

    **(int **)(ctx + 0x34) += (*(int (**)(int))(ctx + 0x38))(*(int *)(ctx + 0x34));

    if (*(signed char *)(ctx + 8) == 0x4e && *(signed char *)(ctx + 9) == 0x33) {
        **(int **)(ctx + 0x34) += extra;
    }

    *(int *)(*(int *)(ctx + 0x64) + *(int *)(ctx + 0xac) * 4) =
        *(int *)(*(int *)(ctx + 0x34) + 0x3b4);
    *(int *)(ctx + 0xcc) = 0;
    *(int *)(ctx + 0xd0) = 0;

    for (i = 0; i < 6; i++) {
        ((int *)ctx)[i + 0x2b] = ((int *)ctx)[i + 0x2b] + 1;
        if (*(int *)(ctx + 0xa8) == ((int *)ctx)[i + 0x2b]) {
            ((int *)ctx)[i + 0x2b] = 0;
        }
    }

    *(int *)(ctx + 0xa0) = *(int *)(ctx + 0xa0) + 1;
    return 1;
}

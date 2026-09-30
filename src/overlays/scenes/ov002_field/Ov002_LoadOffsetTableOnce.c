/* Load the offset table once, and turn its offsets into pointers.
 *
 * Two archive files are possible and the first argument picks between them, but nothing happens at
 * all if the slot at 0x8d7c of the root context is already filled. The loaded blob starts with a
 * count byte followed by that many words, each holding a byte offset from the blob itself; the
 * loop rewrites every one of them in place as a real pointer, re-reading the blob address from the
 * context each pass.
 *
 * Three details carry the original codegen. The slot is bound to a pointer local once, which is
 * what keeps the base and the large offset in the two registers the original addresses through.
 * The count is widened to int before being compared with zero, since comparing the byte itself
 * gives an equality test where the original has a signed one. And the three locals are declared
 * counter, offset, pointer in that order.
 *
 * Ghidra carries the blob as Ov002OffsetTable and the slot as pOffsetTable.
 */

#include "nitro/types.h"

extern char *data_ov002_0207fa00;
extern char gOv002MiMiTrBoxPath[];
extern char gOv002MiMiEviPath[];
extern void *Archive_LoadFile(char *path, int heap, int a, int b);

void Ov002_LoadOffsetTableOnce(int which, int unused, int a, int b) {
    char *ctx = data_ov002_0207fa00;
    void **slot = (void **)(ctx + 0x8d7c);

    if (*slot == 0) {
        int i;
        int off;
        u8 *blob;

        *slot = Archive_LoadFile(which == 0 ? gOv002MiMiTrBoxPath : gOv002MiMiEviPath, 0xf, a, b);
        blob = *(u8 **)slot;
        i = 0;
        if ((int)blob[0] > 0) {
            off = 0;
            do {
                i++;
                *(u8 **)(blob + off + 4) = blob + *(int *)(blob + off + 4);
                blob = *(u8 **)slot;
                off += 4;
            } while (i < blob[0]);
        }
    }
}

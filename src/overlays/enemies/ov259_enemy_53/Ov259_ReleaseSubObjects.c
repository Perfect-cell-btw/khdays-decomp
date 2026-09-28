/* Ov259_ReleaseSubObjects -- release both sub-objects (+0x384, +0x388) and then run the base teardown.
 *
 * ★ The loop index is written as `((int *)obj)[i + 0xe1]`, an ARRAY INDEX WITH THE FIELD OFFSET
 * FOLDED INTO IT (0x384 / 4 = 0xe1). That is what reproduces the ROM's
 * `add r0, obj, i lsl #2 ; ldr r0,[r0,#0x384]`. The two obvious spellings both miss:
 * `*(int *)(obj + i * 4 + 0x384)` strength-reduces to a running pointer (`add r5,r5,#4`), and
 * `((int *)(obj + 0x384))[i]` hoists the base into a register and indexes it. This is the
 * documented "skip base + i*stride loops" class, and it is NOT blocked -- fold the offset into
 * the index and mwcc emits the ROM's form. */
extern void DestroyInstance(int obj);
extern void Ov107_DestroyObject(int obj);

void Ov259_ReleaseSubObjects(int obj) {
    int i;
    for (i = 0; i < 2; i++) {
        DestroyInstance(((int *)obj)[i + 0xe1]);
    }
    Ov107_DestroyObject(obj);
}

/* Emit the local player's box, biased by the panel, and advance the caller's cursor.
 *
 * The box is twelve bytes and is copied onto the stack before being touched, so the source stays
 * as it was. Only the middle word is changed, by adding the panel's own field to it, and the
 * caller's second word moves on by 0xa000 once the box has been emitted.
 *
 * The two lookups stay nested inside the copy call rather than being held in locals, which is what
 * lets each result flow straight through the argument register.
 *
 * Ghidra carries the box as Ov002EmitBox.
 */

typedef unsigned int u32;

extern int Session_GetLocalPlayerIndex(void);
extern void *func_ov022_020881f8(int player);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern int Ov002_GetPanelField0134(void);
extern void Ov002_ProjectWorldToPanel(int *out, int *box, int arg);

void Ov002_EmitLocalPlayerBox(int *out, int arg) {
    int box[3];

    MI_CpuCopy8(func_ov022_020881f8(Session_GetLocalPlayerIndex()), box, 0xc);
    box[1] += Ov002_GetPanelField0134();
    Ov002_ProjectWorldToPanel(out, box, arg);
    out[1] += 0xa000;
}

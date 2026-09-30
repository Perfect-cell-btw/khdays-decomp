/* Release-once guard for a render item: if bit 0x20 of the item's state word is clear, run
 * ReleaseField74AndCleanup on the item body at +4, then set the bit unconditionally. Note the bit
 * is set even when the release was skipped, which is what makes this idempotent rather than merely
 * conditional. Part of the per-view draw-list module on the entity manager (gEntityMgr). Three
 * head tables, 8 entries each, indexed by view: +0x64 drawn FIRST +0x84 drawn SECOND, after its own
 * prepass +0xa4 drawn LAST, through a different renderer (G3d_ResetGlobalState /
 * Billboard_DrawList) rather than RenderNode Nodes are doubly linked (next at +0, prev at +4) and
 * carry their table index in the byte at +0x0a. */

extern void ReleaseField74AndCleanup(int);

void Render_ReleaseItemOnce(int *param_1) {
    if ((*param_1 & 0x20) == 0) {
        ReleaseField74AndCleanup((int)param_1 + 4);
    }
    *param_1 |= 0x20;
}

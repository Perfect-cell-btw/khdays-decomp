/* Release a node's render item if it is still marked pending. Tests bit 2 of bFlags; if set, hands
 * node+0x0c to Render_ReleaseItemOnce and clears the bit. So bit 2 of bFlags means 'this node still
 * owns an item that needs releasing' -- a claim the pairing proves, since nothing else sets or
 * clears it around a release. Part of the per-view draw-list module on the entity manager
 * (data_0204c208). Three head tables, 8 entries each, indexed by view: +0x64 drawn FIRST +0x84
 * drawn SECOND, after its own prepass +0xa4 drawn LAST, through a different renderer
 * (G3d_ResetGlobalState / Billboard_DrawList) rather than RenderNode Nodes are doubly linked (next
 * at +0, prev at +4) and carry their table index in the byte at +0x0a. */

extern void Render_ReleaseItemOnce(void *);

void Render_ReleaseNodeItem(unsigned char *param_1) {
    if ((param_1[8] & 4) == 0) {
        return;
    }
    Render_ReleaseItemOnce(param_1 + 0xc);
    param_1[8] &= ~4;
}

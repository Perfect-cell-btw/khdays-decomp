/* Two passes over items[] (stride 0x58, count elements): first call handler A on
 * each element, then handler B on each. base is preserved across the first pass
 * (kept for the second) so i spills to the stack there. */
extern void Ov000_CreateWidget(int ctx, int element);
extern void Ov000_BuildNodeWithChildren(int ctx, int element);
void Ov000_InstantiateAndLinkElements(int ctx, int base, int count) {
    int i;
    for (i = 0; i < count; i++) {
        Ov000_CreateWidget(ctx, base + i * 0x58);
    }
    for (i = 0; i < count; i++) {
        Ov000_BuildNodeWithChildren(ctx, base + i * 0x58);
    }
}

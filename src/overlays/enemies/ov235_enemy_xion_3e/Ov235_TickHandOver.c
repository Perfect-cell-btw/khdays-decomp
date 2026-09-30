/* Hand-over tick of an ov235 helper: the +0x10 timer accumulates the owner's rate; after 1.0, once
 * (+0x14), the +8 part's channels 0, 2, 4 and 1 restart and it is shown. Once the +4 part's rig is
 * idle, its channels 0, 2, 4 and 1 are restarted looped, the timer clears and the tick hands over
 * to Ov235_TickRampUpPart. */
struct Helper { int owner; char *a; char *b; void *src; int timer; unsigned char done; };

extern void SetSubitemState(int obj, int channel, int a, int b);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov235_TickRampUpPart(int *node);

void Ov235_TickHandOver(int *node)
{
    struct Helper *h = (struct Helper *)node[1];

    h->timer += *(int *)(node[0] + 0x2c);
    if (h->done == 0 && h->timer >= 0x1000) {
        SetSubitemState((int)h->b, 0, 0, 0);
        SetSubitemState((int)h->b, 2, 0, 0);
        SetSubitemState((int)h->b, 4, 0, 0);
        SetSubitemState((int)h->b, 1, 0, 0);
        *(int *)(h->b + 0x5c) &= ~2;
        h->done = 1;
    }
    if (*(unsigned char *)(h->a + 0xad) == 0) {
        SetSubitemState((int)h->a, 0, 1, 1);
        SetSubitemState((int)h->a, 2, 1, 1);
        SetSubitemState((int)h->a, 4, 1, 1);
        SetSubitemState((int)h->a, 1, 1, 1);
        h->timer = 0;
        SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), (void *)Ov235_TickRampUpPart);
        return;
    }
}

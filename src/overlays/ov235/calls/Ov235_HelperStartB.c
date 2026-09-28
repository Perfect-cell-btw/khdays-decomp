/* Start of an ov235 helper (two parts): the +4 part is shown (bit 1 of +0x5c cleared, bit 0
 * raised), its animation channels 0, 2, 4 and 1 restart once and it takes the +0xc source pose; the
 * +8 part is raised (bit 0) and takes the same pose; the +0x10 timer and +0x14 flag clear and the
 * helper installs its slot-1 (Ov235_TickHandOver) and slot-2 (Ov235_HelperSyncPose) ticks. */
typedef struct { int w[11]; } Srt;
struct Part { char pad[0x30]; Srt pose; };
struct b1 { unsigned int b0 : 1; };
struct Helper { int owner; struct Part *a; struct Part *b; Srt *src; int timer; unsigned char done; };

extern void SetSubitemState(int obj, int channel, int a, int b);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov235_TickHandOver(int *node);
extern void Ov235_HelperSyncPose(int *node);

void Ov235_HelperStartB(int *node)
{
    struct Helper *h = (struct Helper *)node[1];

    *(int *)((char *)h->a + 0x5c) &= ~2;
    ((struct b1 *)((char *)h->a + 0x5c))->b0 = 1;
    SetSubitemState((int)h->a, 0, 0, 0);
    SetSubitemState((int)h->a, 2, 0, 0);
    SetSubitemState((int)h->a, 4, 0, 0);
    SetSubitemState((int)h->a, 1, 0, 0);
    h->a->pose = *h->src;
    ((struct b1 *)((char *)h->b + 0x5c))->b0 = 1;
    h->b->pose = *h->src;
    h->timer = 0;
    h->done = 0;
    SetIndexedSlot(node, 1, (void *)Ov235_TickHandOver);
    SetIndexedSlot(node, 2, (void *)Ov235_HelperSyncPose);
}

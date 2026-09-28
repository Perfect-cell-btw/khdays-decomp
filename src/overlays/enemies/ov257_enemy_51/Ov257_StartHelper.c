/* Start of an ov257 helper (two parts): the +0 part is shown (bit 1 of +0x5c cleared, bit 0
 * raised), its animation channels 0, 2, 4 and 1 restart once and it takes the +8 source pose; the
 * +4 part is raised (bit 0) and takes the same pose; the +0xc timer and +0x10 flag clear and the
 * helper installs its slot-1 (Ov257_TickWindUp) and slot-2 (Ov257_TrailHelperFollow) ticks. */
typedef struct { int w[11]; } Srt;
struct Part { char pad[0x30]; Srt pose; };
struct b1 { unsigned int b0 : 1; };
struct Helper { struct Part *a; struct Part *b; Srt *src; int timer; unsigned char done; };

extern void SetSubitemState(int obj, int channel, int a, int b);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov257_TickWindUp(int *node);
extern void Ov257_TrailHelperFollow(int *node);

void Ov257_StartHelper(int *node)
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
    SetIndexedSlot(node, 1, (void *)Ov257_TickWindUp);
    SetIndexedSlot(node, 2, (void *)Ov257_TrailHelperFollow);
}

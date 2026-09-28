/* Start of the second ov255 helper: its +4 part is shown (bit 1 of +0x5c cleared), animation
 * channels 2 and 0 restart and the helper installs its slot-1 (Ov255_ShowReactionReady) and slot-2
 * (Ov255_SwirlTick) ticks. */
struct Helper2 { int owner; char *part; };

extern void SetSubitemState(int obj, int channel, int a, int b);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov255_SwirlTick(int *node);
extern void Ov255_ShowReactionReady(int *node);

void Ov255_StartHelper2(int *node)
{
    struct Helper2 *h = (struct Helper2 *)node[1];

    *(int *)(h->part + 0x5c) &= ~2;
    SetSubitemState((int)h->part, 2, 0, 0);
    SetSubitemState((int)h->part, 0, 0, 0);
    SetIndexedSlot(node, 1, (void *)Ov255_ShowReactionReady);
    SetIndexedSlot(node, 2, (void *)Ov255_SwirlTick);
}

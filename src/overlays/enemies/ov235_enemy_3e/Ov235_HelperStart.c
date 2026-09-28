/* Start of an ov235 helper: its +4 part is shown (bit 1 of +0x5c cleared, bit 0 raised), animation
 * channels 0 and 2 are restarted once, the part takes the +8 source pose at +0x30, and the helper
 * installs its slot-1 (Ov235_ShowReactionReady) and slot-2 (Ov235_CopyBlock44Alt) ticks. */
typedef struct { int w[11]; } Srt;
struct Part { char pad[0x30]; Srt pose; };
struct b1 { unsigned int b0 : 1; };

extern void SetSubitemState(int obj, int channel, int a, int b);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov235_ShowReactionReady(int *node);
extern void Ov235_CopyBlock44Alt(int *node);

void Ov235_HelperStart(int *node)
{
    int *state = (int *)node[1];

    *(int *)(state[1] + 0x5c) &= ~2;
    ((struct b1 *)(state[1] + 0x5c))->b0 = 1;
    SetSubitemState(state[1], 0, 0, 0);
    SetSubitemState(state[1], 2, 0, 0);
    ((struct Part *)state[1])->pose = *(Srt *)state[2];
    SetIndexedSlot(node, 1, (void *)Ov235_ShowReactionReady);
    SetIndexedSlot(node, 2, (void *)Ov235_CopyBlock44Alt);
}

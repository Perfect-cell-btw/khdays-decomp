/* Start of an ov255 helper (twin of ov235 d1a88): its +0 part is shown (bit 1 of +0x5c cleared, bit 0 raised),
 * animation channels 0, 2, 4 and 1 are restarted once, the part takes the +4 source pose at +0x30,
 * and the helper installs its slot-1 (Ov255_TickRearmPart) and slot-2 (Ov255_CopyBlock44) ticks. */
typedef struct { int w[11]; } Srt;
struct Part { char pad[0x30]; Srt pose; };
struct b1 { unsigned int b0 : 1; };

extern void SetSubitemState(int obj, int channel, int a, int b);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov255_TickRearmPart(int *node);
extern void Ov255_CopyBlock44(int *node);

void Ov255_SnapshotPoseRegister2(int *node)
{
    int *state = (int *)node[1];

    *(int *)(state[0] + 0x5c) &= ~2;
    ((struct b1 *)(state[0] + 0x5c))->b0 = 1;
    SetSubitemState(state[0], 0, 0, 0);
    SetSubitemState(state[0], 2, 0, 0);
    SetSubitemState(state[0], 4, 0, 0);
    SetSubitemState(state[0], 1, 0, 0);
    ((struct Part *)state[0])->pose = *(Srt *)state[1];
    SetIndexedSlot(node, 1, (void *)Ov255_TickRearmPart);
    SetIndexedSlot(node, 2, (void *)Ov255_CopyBlock44);
}

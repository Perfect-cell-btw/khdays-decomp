/* Move entry: bit 7 of the actor's +0x60 high byte clears and bit 0 is set, the +0x388 shape is
 * armed, pose 2 plays and the node moves to 020d2a2c. */
typedef unsigned short u16;
struct Hw60 { u16 lo : 8; u16 hi : 8; };
typedef struct { unsigned f : 8; } B8;

extern void Ov107_PostTagUpdate(int actor, int pose, int flag);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov254_AiStep_QueueAction0OnAnimEnd_2(void);

void Ov254_ArmEntry(int *node)
{
    int *state = (int *)node[1];

    ((struct Hw60 *)(*state + 0x60))->hi &= ~0x80;
    {
        u16 hw = *(u16 *)(*state + 0x60);
        *(u16 *)(*state + 0x60) = (hw & ~0xff00) |
            ((((((unsigned int)hw << 0x10) >> 0x18) | 1) << 0x18) >> 0x10);
    }
    ((B8 *)(*(int *)(*state + 0x388) + 8))->f |= 1;
    Ov107_PostTagUpdate(*state, 2, 0);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov254_AiStep_QueueAction0OnAnimEnd_2);
}

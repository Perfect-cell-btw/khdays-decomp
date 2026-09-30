/* Enter the ov137 enemy's return: raises bits 1/2/7 of the hw60 high byte, drops bit 0 of the
 * +0x384 item's +8 word, fires reaction 0x49 (mode 0) at the +0x50 point, queues sub-state 0
 * and ends the state. */
struct hw60 { unsigned short lo : 8, hi : 8; };
struct w8 { unsigned int lo : 8, rest : 24; };

extern void Ov107_BuildAndSendUpdate(int actor, int a, int id, void *at);
extern void SetIndexedSlot(int *node, int slot, void *cb);

void Ov138_EnterReturn(int *node)
{
    int *state = (int *)node[1];

    ((struct hw60 *)(*state + 0x60))->hi |= (unsigned char)0x86;
    ((struct w8 *)(*(int *)(*state + 0x384) + 8))->lo &= ~1;
    Ov107_BuildAndSendUpdate(*state, 0, 0x49, (void *)state[0x14]);
    *(unsigned char *)(*state + 0x1c7) = 0;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
}

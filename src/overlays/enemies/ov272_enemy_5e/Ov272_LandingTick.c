/* Landing tick of the ov272 enemy. Once the owner's +0x60 low byte has bit 0 set, the owner is
 * placed 1.8 above the +0x48 point, takes its +0x1c9 return sub-state as the requested one
 * (+0x1c7) and the node's slot is released with no follow-up handler. */
typedef struct { int x, y, z; } Vec3;
struct hw60 { unsigned short lo : 8, hi : 8; };

extern void Ov107_MoveNodeAndRelayout(int owner, Vec3 *pos);
extern void SetIndexedSlot(int *node, int slot, void *cb);

void Ov272_LandingTick(int *node)
{
    int *state = (int *)node[1];
    Vec3 pos;

    if ((((struct hw60 *)(*state + 0x60))->lo & 1) == 0) {
        return;
    }
    {
        Vec3 *at = (Vec3 *)state[0x12];
        int x = at->x;
        int y = at->y;
        int z = at->z;
        pos.x = x;
        pos.y = y + 0x1ccc;
        pos.z = z;
    }
    Ov107_MoveNodeAndRelayout(*state, &pos);
    *(signed char *)(*state + 0x1c7) = *(signed char *)(*state + 0x100 + 0xc9);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
}

/* Publish the pounce landing: send the canned 4-byte block from the config table to the owner's
 * notify hook, play animation 6 and clear the byte at +0x74 before handing off.
 *
 * Matched byte-exact 2026-07-23, closing an old park. The config pair is a STRUCT-TYPED GLOBAL
 * copied with a plain struct assignment, and `node` is loaded BEFORE that copy: the copy is then
 * one unit for the scheduler, so the node load drops into the gap between the two halfword loads
 * and the two halfword stores, which is where the ROM has it.
 *
 * One of two byte-identical siblings. */
struct Pair16 { unsigned short a, b; };

extern int Ov107_PostTagUpdate(int obj, int a, int b);
extern int SetIndexedSlot(int self, int idx, void *handler);
extern void Ov278_StompLandingTick(int self);
struct Blk { unsigned short pad[10]; struct Pair16 p; };
extern struct Blk data_ov278_020d639c;

void Ov278_PublishPounceLanding(int self) {
    struct Pair16 local;
    int *node;
    void (*method)(int, void *, int);
    node = *(int **)(self + 4);
    local = data_ov278_020d639c.p;
    method = *(void (**)(int, void *, int))(*node + 0x24);
    if (method != 0) {
        method(*node, &local, 4);
    }
    Ov107_PostTagUpdate(*node, 6, 0);
    *(unsigned char *)((char *)node + 0x74) = 0;
    SetIndexedSlot(self, *(signed char *)(self + 0x20), &Ov278_StompLandingTick);
}

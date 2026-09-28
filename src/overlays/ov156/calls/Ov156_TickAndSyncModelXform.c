/* Ov107_ProcessObjectTick, then copies the actor's 44-byte transform block into its model (+0x10).
 */

extern int Ov107_ProcessObjectTick();

struct Block { int a[11]; };

struct Obj {
    char pad[0xa0];
    struct Block block;
    char pad2[0x388 - 0xa0 - sizeof(struct Block)];
    struct Block **pp;
};

void Ov156_TickAndSyncModelXform(struct Obj *this) {
    Ov107_ProcessObjectTick(this);
    *(struct Block *)((char *)(*this->pp) + 0x10) = this->block;
}

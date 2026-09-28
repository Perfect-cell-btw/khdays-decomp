/* Runs the object tick, then copies the transform into the model. */

extern int Ov107_ProcessObjectTick();

struct Block { int a[11]; };

struct Obj {
    char pad[0xa0];
    struct Block block;
    char pad2[0x388 - 0xa0 - sizeof(struct Block)];
    struct Block **pp;
};

void Ov260_TickSyncXform(struct Obj *this, int delta) {
    Ov107_ProcessObjectTick(this, delta);
    *(struct Block *)((char *)(*this->pp) + 0x10) = this->block;
}

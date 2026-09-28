typedef struct {
    void *ptr;
    int val;
} Ov107Slot;

typedef struct Ov107Object {
    unsigned char pad_000[0xb0];
    unsigned short field_b0;
    unsigned char pad_b2[2];
    Ov107Slot slots[8];
} Ov107Object;

extern void FreeInstanceMemory(void *p);

void Ov107_Spawner_FreeDataBlocks(Ov107Object *obj)
{
    int i;
    for (i = 0; i < 8; i++) {
        if (obj->slots[i].ptr != 0) {
            FreeInstanceMemory(obj->slots[i].ptr);
            obj->slots[i].ptr = 0;
        }
        obj->slots[i].val = 0;
    }
    obj->field_b0 = 0;
}

/* Per-frame hook: run the object's optional +0x30 callback when its state is 1,
 * then its optional +0x14 callback with bit 1 of the region's flags; number the
 * nodes of the list at +0x22c, register the +0x1a8 sub-object, every node of the
 * list at +0x260 and every slot's +0x14 sub-object into the region's child list,
 * and finish with Ov107_RegisterChildInRegion. */
typedef struct Obj Obj;

typedef struct {
    char pad_00[0x14];
    int field_14;
} Entry;

typedef struct {
    int pad[16];
    signed int b0:1;
    signed int b1:1;
} RegionFlags;

typedef struct {
    char pad_00[0x104];
    int field_104;
} Region;

struct Obj {
    char pad_00[0x14];
    void (*field_14)(Obj *self, int flag);
    char pad_18[0x30 - 0x18];
    void (*field_30)(Obj *self);
    char pad_34[0x50 - 0x34];
    int field_50;
    char pad_54[0x1a8 - 0x54];
    int field_1a8;
    char pad_1ac[0x22c - 0x1ac];
    char list_22c[0x260 - 0x22c];
    char list_260[0x350 - 0x260];
    Entry *slots[8];         /* +0x350 */
};

typedef struct {
    char pad_00[4];
    unsigned char index;
} Node;

extern void RegisterSubscriberSlot(int list, int child);
extern void *List_First(void *list);
extern void *List_Next(void *list);
extern void Ov107_RegisterChildInRegion(Obj *obj, Region *region);

void Ov107_HandleRegionEvent(Obj *obj, Region *region) {
    if (obj->field_50 == 1 && obj->field_30 != 0) {
        obj->field_30(obj);
    }

    {
        int flag = ((RegionFlags *)region)->b1;
        if (obj->field_14 != 0) {
            obj->field_14(obj, flag);
        }
    }

    {
        int count = 0;
        Node *node = List_First(obj->list_22c);
        while (node != 0) {
            node->index = count++;
            node = List_Next(obj->list_22c);
        }
    }

    RegisterSubscriberSlot(region->field_104, obj->field_1a8);

    {
        void *node = List_First(obj->list_260);
        while (node != 0) {
            RegisterSubscriberSlot(region->field_104, *(int *)node);
            node = List_Next(obj->list_260);
        }
    }

    {
        int i;
        for (i = 0; i < 8; i++) {
            Entry *e = obj->slots[i];
            if (e != 0 && e->field_14 != 0) {
                RegisterSubscriberSlot(region->field_104, e->field_14);
            }
        }
    }

    Ov107_RegisterChildInRegion(obj, region);
}

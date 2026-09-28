/* Container node tick: runs the callbacks of the active children and sums the finished ones. */

typedef struct Ov107_9784_Entry {
    char pad[0xc];
    void (*callback)(struct Ov107_9784_Entry *entry, int b);
    char pad2[0x40 - 0x10];
    int flags;
} Ov107_9784_Entry;

typedef struct Ov107_9784_Self {
    char pad[0x3c];
    void *field_3c;
    int flags;              /* 0x40 */
    char pad2[0x44 - 0x44]; /* list head starts right at 0x44 */
    char list[0x78 - 0x44];
    int accum;               /* 0x78 */
    char pad3[0xa4 - 0x7c];
    int field_a4;             /* 0xa4 */
} Ov107_9784_Self;

extern int List_First(void *listHead);
extern int List_Next(void *listHead);
extern int Ov107_Region_CountFlaggedMembers(void *entry);
extern void Ov107_Region_TickChildren(void *self, int b);
extern void ObjList_Update(void *ptr, int b);

void Ov107_ContainerNode_Tick(Ov107_9784_Self *self, int b)
{
    int allBit2 = 1;
    void *node;

    self->accum = 0;
    self->field_a4 += b;

    node = (void *)List_First(self->list);
    while (node != 0) {
        Ov107_9784_Entry *entry = *(Ov107_9784_Entry **)node;
        int flags = entry->flags;

        if (!((flags << 0x1d) >> 0x1f)) {
            if ((flags << 0x1e) >> 0x1f) {
                if (entry->callback != 0) {
                    entry->callback(entry, b);
                }
            }
            allBit2 = 0;
        } else {
            self->accum += Ov107_Region_CountFlaggedMembers(entry);
        }
        node = (void *)List_Next(self->list);
    }

    self->flags = (self->flags & ~4) | ((unsigned int)(allBit2 << 31) >> 29);
    Ov107_Region_TickChildren(self, b);
    ObjList_Update(self->field_3c, b);
}

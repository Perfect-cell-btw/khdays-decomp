/* Finishes the AI task and removes the actor's model and part nodes from the region list (+0x104),
 * then the base detach. */

typedef struct {
    char pad_00[0x14];
    int field_14;
} Entry;

typedef struct {
    char pad_00[0x3c];
    int field_3c;
    char pad_40[0x214 - 0x40];
    int field_214;
    char pad_218[0x260 - 0x218];
    char list_260[0xc];
    char pad_26c[0x350 - 0x26c];
    Entry *slots[8];         /* +0x350 */
} Obj;

typedef struct {
    char pad_00[0x104];
    int field_104;
} Param1;

extern void *FindListEntryByField4(int this_, int arg1);
extern void Task_MarkFinished(void *p);
extern void RemoveChildFromListByPtr(int a, int b);
extern void *List_First(void *list);
extern void *List_Next(void *list);
extern void Ov107_RemoveChildFromRegion(void *obj, void *param1);

void Ov107_Actor_DetachFromRegion(Obj *obj, Param1 *param1) {
    if (obj->field_214 != 0) {
        Task_MarkFinished(FindListEntryByField4(obj->field_3c, obj->field_214));
        obj->field_214 = 0;
    }

    RemoveChildFromListByPtr(param1->field_104, *(int *)((char *)obj + 0x1a8));

    {
        void *node = List_First(obj->list_260);
        while (node != 0) {
            RemoveChildFromListByPtr(param1->field_104, *(int *)node);
            node = List_Next(obj->list_260);
        }
    }

    {
        int i;
        for (i = 0; i < 8; i++) {
            Entry *e = obj->slots[i];
            if (e != 0 && e->field_14 != 0) {
                RemoveChildFromListByPtr(param1->field_104, e->field_14);
            }
        }
    }

    Ov107_RemoveChildFromRegion(obj, param1);
}

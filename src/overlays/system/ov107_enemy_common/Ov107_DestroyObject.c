/* Destroys an enemy object: its instance, its registry entry, its part list and lists, its eight
 * attached nodes, and the base node. */

#include "game/enemy_common.h"

typedef struct Self68ec {
    char pad00[0x3c];
    void *field_3c;
    char pad40[0x1a8 - 0x40];
    void *field_1a8;
    char pad1ac[0x214 - 0x1ac];
    int field_214;
    char pad218[0x22c - 0x218];
    char list_22c[0x260 - 0x22c];
    char list_260[0x350 - 0x260];
    void *arr350[8];
} Self68ec;

extern void DestroyInstance(void *obj);
extern void *FindListEntryByField4(void *this_, int arg1);
extern void Task_MarkFinished(void *p);
extern void *List_First(void *list);
extern void *List_Next(void *list);
extern void func_ov107_020c3190(void *obj);
extern void FreeInstanceMemory(void *p);
extern void NNSi_FndDestroyDoubleList(void *list);

void Ov107_DestroyObject(Self68ec *self)
{
    void **entry;
    int i;

    DestroyInstance(self->field_1a8);

    if (self->field_214 != 0) {
        void *r = FindListEntryByField4(self->field_3c, self->field_214);
        Task_MarkFinished(r);
        self->field_214 = 0;
    }

    entry = (void **)List_First(self->list_22c);
    if (entry != 0) {
        do {
            void *elem = *entry;
            if (elem != 0)
                func_ov107_020c3190(elem);
            entry = (void **)List_Next(self->list_22c);
        } while (entry != 0);
    }

    NNSi_FndDestroyDoubleList(self->list_22c);
    NNSi_FndDestroyDoubleList(self->list_260);

    for (i = 0; i < 8; i++) {
        void *node = self->arr350[i];
        if (node != 0) {
            void *f14 = *(void **)((char *)node + 0x14);
            if (f14 != 0)
                DestroyInstance(f14);
            FreeInstanceMemory(node);
        }
    }

    Ov107_DestroyNode((char *)self);
}

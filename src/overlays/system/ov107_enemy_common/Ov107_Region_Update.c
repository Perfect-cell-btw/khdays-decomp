/* Runs the members' attach hooks, their pairwise contact hooks and trigger hooks (host only), then
 * the children and callbacks. */

typedef unsigned short u16;
typedef unsigned char u8;

typedef struct Node2 {
    struct Node2 *prev;
    struct Node2 *next;
    int key;
    void *data;
} Node2;

typedef struct GameObj {
    u16 flags;
    char pad2[0x44 - 2];
    void (*onAttach)(struct GameObj *self);
    void (*onTrigger)(struct GameObj *self, void *param1);
    void (*onPair)(struct GameObj *a, struct GameObj *b);
    char pad50[0x60 - 0x50];
    u16 flags60;
} GameObj;

extern void *List_First(int list);
extern void *List_Next(int list);
extern unsigned int Session_GetLocalPlayerIndex(void);
extern void Ov107_Region_TickChildren(void *self, void *param1);
extern void RefreshObjectCallbacks(int *ptr, int arg);

void Ov107_Region_Update(char *self, void *param1) {
    void *node;
    Node2 *outer, *inner;

    node = List_First((int)(self + 0x44));
    if (node != 0) {
        do {
            GameObj *obj = *(GameObj **)node;
            if (obj->flags & 0x20) {
                if (obj->onAttach) obj->onAttach(obj);
            }
            node = List_Next((int)(self + 0x44));
        } while (node != 0);
    }

    if (Session_GetLocalPlayerIndex() == 0) {
        for (outer = *(Node2 **)(self + 0x48);
             outer != (Node2 *)(self + 0x54) && outer->next != (Node2 *)(self + 0x54);
             outer = outer->next) {
            GameObj *a = *(GameObj **)outer->data;
            if (a->flags & 0x20) {
                unsigned int aByte = (unsigned int)(a->flags60 << 24) >> 24;
                if ((aByte & 1) && !(aByte & 2)) {
                    for (inner = outer->next; inner != (Node2 *)(self + 0x54); inner = inner->next) {
                        GameObj *b = *(GameObj **)inner->data;
                        if (b->flags & 0x20) {
                            unsigned int bByte = (unsigned int)(b->flags60 << 24) >> 24;
                            if ((bByte & 1) && !(bByte & 2)) {
                                if (!(a->flags & 0x80) || !(b->flags & 0x80)) {
                                    if (a->onPair) a->onPair(a, b);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if (Session_GetLocalPlayerIndex() == 0) {
        node = List_First((int)(self + 0x44));
        if (node != 0) {
            do {
                GameObj *obj = *(GameObj **)node;
                if (obj->flags & 0x20) {
                    unsigned int byte = (unsigned int)(obj->flags60 << 24) >> 24;
                    if (byte & 1) {
                        if (obj->onTrigger) obj->onTrigger(obj, param1);
                    }
                }
                node = List_Next((int)(self + 0x44));
            } while (node != 0);
        }
    }

    Ov107_Region_TickChildren(self, param1);
    RefreshObjectCallbacks(*(int **)(self + 0x104), (int)param1);
}

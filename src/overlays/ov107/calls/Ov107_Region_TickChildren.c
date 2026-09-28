typedef void (*Callback)(void *self, void *param);

typedef struct {
    char pad_00[0xc];
    Callback callback;   /* +0xc */
    char pad_10[0x40 - 0xc - 4];
    int flags;            /* +0x40 */
} Entity;

extern void *List_First(void *list);
extern void *List_Next(void *list);

void Ov107_Region_TickChildren(void *obj, void *param1) {
    void *node = List_First((char *)obj + 0x44);
    while (node != 0) {
        Entity *e = *(Entity **)node;
        int flag = (e->flags << 30) >> 31;
        if (flag) {
            if (flag && e->callback) {
                e->callback(e, param1);
            }
        }
        node = List_Next((char *)obj + 0x44);
    }
}

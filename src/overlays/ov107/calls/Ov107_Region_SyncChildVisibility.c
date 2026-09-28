typedef void (*Callback)(void *self, int param);

typedef struct {
    signed int flag0 : 1;   /* bit0 */
    signed int flag1 : 1;   /* bit1 */
    signed int flag2 : 1;   /* bit2 */
    signed int rest  : 29;
} Flags;

typedef struct {
    char pad_00[0x10];
    Callback cb;             /* +0x10 */
    char pad_14[0x40 - 0x14];
    Flags flags;              /* +0x40 */
} Entity;

extern void *List_First(void *list);
extern void *List_Next(void *list);

void Ov107_Region_SyncChildVisibility(void *self)
{
    void *node = List_First((char *)self + 0x44);
    if (node == 0) return;

    do {
        Entity *e = *(Entity **)node;
        if (e->flags.flag1) {
            if (!e->flags.flag0) {
                if (e->flags.flag2) {
                    if (e->cb) e->cb(e, 1);
                }
            } else {
                if (e->flags.flag0) {
                    if (e->flags.flag2) {
                        if (e->cb) e->cb(e, 0);
                    }
                }
            }
        }
        node = List_Next((char *)self + 0x44);
    } while (node != 0);
}

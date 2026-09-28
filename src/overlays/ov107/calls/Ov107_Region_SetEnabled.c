typedef void (*Callback)(void *self, int param);

typedef struct {
    unsigned bit0 : 1;
    unsigned enabled : 1;   /* bit 1 */
    unsigned rest : 30;
} Flags;

typedef struct {
    char pad_00[0x14];
    Callback callback;   /* +0x14 */
} Entity;

extern void *List_First(void *list);
extern void *List_Next(void *list);

void Ov107_Region_SetEnabled(void *self, int flag)
{
    Flags *flags = (Flags *)((char *)self + 0x40);
    void *node;

    flags->enabled = flag;

    node = List_First((char *)self + 0x44);
    while (node != 0) {
        Entity *e = *(Entity **)node;
        if (e->callback) {
            e->callback(e, flag);
        }
        node = List_Next((char *)self + 0x44);
    }

    flags->enabled = flag;
}

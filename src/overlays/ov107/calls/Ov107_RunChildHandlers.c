/* Ov107_RunChildHandlers -- walk the object's child list at +0x44 and run each child's +0x34 handler
 * (skipping the ones that have none). */
extern int List_First(void *list);
extern int List_Next(void *list);

void Ov107_RunChildHandlers(int obj) {
    int *node;
    void (*cb)(int);
    node = (int *)List_First((void *)(obj + 0x44));
    while (node != 0) {
        cb = *(void (**)(int))(node[0] + 0x34);
        if (cb != 0) {
            cb(node[0]);
        }
        node = (int *)List_Next((void *)(obj + 0x44));
    }
}

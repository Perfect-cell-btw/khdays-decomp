/* Ov107_EnqueueValue -- store a value into a freshly reserved list cell, ov107.
 * Reserves the cell (List_InsertSorted on the pool @node+0x260) and writes val into it. */
extern int *List_InsertSorted(void *pool, int, int);
void Ov107_EnqueueValue(char *node, int val) {
    *List_InsertSorted(node + 0x260, 4, 0x64) = val;
}

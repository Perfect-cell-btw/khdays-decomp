/* Ov107_EnqueueValue -- store a value into a freshly reserved list cell, ov107.
 * Reserves the cell (List_InsertSorted on the actor's list at +0x260, Actor.list260) and writes val
 * into it. Its callers hold the actor as bytes, so it takes it so. */
extern int *List_InsertSorted(void *pool, int, int);
void Ov107_EnqueueValue(char *node, int val) {
    *List_InsertSorted(node + 0x260, 4, 0x64) = val;
}

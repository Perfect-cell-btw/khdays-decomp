/* Search the linked list at param_1+0x4d4 for the first object whose u16 id at
 * +0 equals param_2; return it, or NULL. */
extern void *Ov025_FindListObjectWithField10Zero(void *list, void *obj);

void *Ov025_FindListObjectByKey_2(int param_1, int param_2) {
    void *obj = Ov025_FindListObjectWithField10Zero((void *)(param_1 + 0x4d4), 0);
    while (obj != 0) {
        if (*(unsigned short *)obj == param_2) {
            return obj;
        }
        obj = Ov025_FindListObjectWithField10Zero((void *)(param_1 + 0x4d4), obj);
    }
    return obj;
}

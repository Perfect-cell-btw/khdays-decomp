/* Calls each child entry's optional handler at +0x18 with `value`, then folds bit 0 of
 * `value` into self->field_40 (preserving the other bits). */
extern int List_First(void *list);
extern int List_Next(void *list);

void Ov107_BroadcastValueToChildren(char *self, int value) {
    int p = List_First(self + 0x44);
    while (p != 0) {
        int e = *(int *)p;
        void (*fn)(int, int) = *(void (**)(int, int))(e + 0x18);
        if (fn != 0) {
            fn(e, value);
        }
        p = List_Next(self + 0x44);
    }
    *(int *)(self + 0x40) = (*(int *)(self + 0x40) & ~1) | (value & 1);
}

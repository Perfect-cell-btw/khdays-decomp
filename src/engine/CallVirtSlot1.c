/* Calls the object's vtable slot 1 on its +4 sub-object. */

int CallVirtSlot1(int *p, int q) {
    return ((int (*)(int *, int))(((int *)p[6])[1]))((int *)((char *)p + 4), q);
}

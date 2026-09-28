extern void *List_First(void *list);
extern int List_RemoveByHandle(void *list, void *handle);
extern void *List_Next(void *list);

typedef void (*Callback)(void *target, void *self);

typedef struct Target {
    void *field_00;
    int field_04;
    char pad_08[0x2c - 0x08];
    Callback field_2c;
} Target;

void Ov107_Region_UnlinkChild(void *self, Target *target)
{
    void *list;
    void *handle;

    if (target == 0) {
        return;
    }

    list = (char *)self + 0x44;
    handle = List_First(list);
    if (handle == 0) {
        return;
    }

    for (;;) {
        if (*(Target **)handle == target) {
            target->field_04 = 0;
            if (target->field_2c != 0) {
                target->field_2c(target, self);
            }
            List_RemoveByHandle(list, handle);
            return;
        }
        handle = List_Next(list);
        if (handle == 0) {
            return;
        }
    }
}

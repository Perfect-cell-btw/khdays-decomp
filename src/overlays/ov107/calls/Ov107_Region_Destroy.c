/* Calls every child's destroy hook, destroys the list and the instance. */

extern int List_First(void *o);
extern int List_Next(void *o);
extern void NNSi_FndDestroyDoubleList(void *list);
extern void Ov107_DestroyInstance(void *obj);

void Ov107_Region_Destroy(char *self)
{
    void *list = self + 0x44;
    int *it;

    for (it = (int *)List_First(list); it != 0; it = (int *)List_Next(list)) {
        void *elem = *(void **)it;
        void (*cb)(void *) = *(void (**)(void *))((char *)elem + 8);
        if (cb != 0) {
            cb(elem);
        }
    }

    NNSi_FndDestroyDoubleList(list);
    Ov107_DestroyInstance(self);
}

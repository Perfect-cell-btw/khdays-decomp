typedef struct {
    char pad0[4];
    int f4;
    char pad1[0x1d8 - 8];
    void *f1d8;
} Elem;

typedef struct {
    char pad[4];
    int container;
} Owner;

extern int List_First(void *o);
extern int List_Next(void *o);
extern int Ov107_HitShape_TestSphere(void *p, void *source, int flag);

int Ov107_CollectSphereOverlaps(Owner *owner, void *source, void **results)
{
    int count = 0;
    void *list = (void *)(owner->container + 0xa8);
    int *it;
    Elem *elem;

    it = (int *)List_First(list);
    elem = !it ? 0 : *(Elem **)it;

    while (elem != 0) {
        if (elem->f4 == owner->container) {
            if (Ov107_HitShape_TestSphere(elem->f1d8, source, 0) != 0) {
                results[count] = elem;
                count++;
            }
        }
        it = (int *)List_Next(list);
        elem = !it ? 0 : *(Elem **)it;
    }

    return count;
}

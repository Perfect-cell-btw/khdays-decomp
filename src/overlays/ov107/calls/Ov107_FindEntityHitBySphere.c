typedef struct {
    char pad[4];
    void *container;
} Owner;

typedef struct {
    char pad0[0x60];
    unsigned short half60 : 8;
    char pad1[0x1ac - 0x62];
    unsigned short flags1ac;
} Elem;

typedef struct {
    void *f0;
    char pad[4];
    unsigned int f8 : 8;
} Inner;

extern int List_First(void *o);
extern int List_Next(void *o);
extern int Ov107_HitShape_TestSphere(void *p, void *position, int flag);

Elem *Ov107_FindEntityHitBySphere(Owner *owner, void *position, void **outHit)
{
    Inner *innerIt;
    void *container;
    int *outerIt;
    Elem *cand;
    unsigned short flags1ac;
    int flag;

    container = owner->container;
    outerIt = (int *)List_First((char *)container + 0x80);
    cand = !outerIt ? 0 : *(Elem **)outerIt;

    while (cand != 0) {
        if (cand == (Elem *)owner) {
            goto nextOuter;
        }

        if (!(cand->half60 & 1)) {
            goto nextOuter;
        }

        flags1ac = cand->flags1ac;
        if (flags1ac & 1) {
            goto nextOuter;
        }
        if (flags1ac & 2) {
            goto nextOuter;
        }
        if (flags1ac & 4) {
            goto nextOuter;
        }

        innerIt = (Inner *)List_First((char *)cand + 0x22c);
        if (innerIt != 0) {
            flag = 0;
            do {
                if (innerIt->f8 & 1) {
                    if (Ov107_HitShape_TestSphere(innerIt->f0, position, flag) != 0) {
                        if (outHit != 0) {
                            *outHit = innerIt;
                        }
                        return cand;
                    }
                }
                innerIt = (Inner *)List_Next((char *)cand + 0x22c);
            } while (innerIt != 0);
        }

    nextOuter:
        outerIt = (int *)List_Next((char *)container + 0x80);
        cand = !outerIt ? 0 : *(Elem **)outerIt;
    }

    return 0;
}

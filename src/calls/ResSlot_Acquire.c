/* Acquires a resource slot: with data_020427f0 temporarily set to `withTex`, the first user loads
 * the data (an 'HPAK' pack through Obj_RelocateSections with textures, anything else through
 * G3dRes_DefaultSetup); the use count (+2) grows, and with `withTex` the texture count (+4) too. Returns
 * the resource data (+0xc). Counterpart of ResSlot_ReleaseResource. */
extern void Obj_RelocateSections(void *pack, int mode);
extern void G3dRes_DefaultSetup(void *data);
extern int data_020427f0;

struct S {
    short _0;
    unsigned short x2;
    unsigned short x4;
    char _6[6];
    void *xc;
};

void *ResSlot_Acquire(struct S *p, int withTex)
{
    int saved = data_020427f0;

    data_020427f0 = withTex;
    if (p->x2 == 0) {
        if (*(int *)p->xc == 0x4850414B) {
            Obj_RelocateSections(p->xc, 1);
        } else {
            G3dRes_DefaultSetup(p->xc);
        }
    }
    p->x2++;
    data_020427f0 = saved;
    if (withTex != 0) {
        p->x4++;
    }
    return p->xc;
}

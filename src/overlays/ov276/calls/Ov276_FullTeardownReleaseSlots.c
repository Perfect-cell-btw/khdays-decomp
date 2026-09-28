struct row8 { int a, b; };

extern void FreeAllResourceTables(int a, int b, int c, int d);
extern void DestroyInstance(int instance);
extern void Ov107_ActionResource_Destroy(int p);
extern void Ov107_DestroyObject(int obj);

// Full teardown: run the base cleanup (this+0x384, forwarded args), clear the
// active channel (this[0x390]), destroy the primary sub-object (this[0x3a8]) and
// the aux channel (this[0x470]), free the 6 optional slot instances
// (this + i*8 + 0x488), then notify the owner.
void Ov276_FullTeardownReleaseSlots(int *this, int p2, int p3, int p4)
{
    int i;
    FreeAllResourceTables((int)this + 0x384, p2, p3, p4);
    *(int *)((int)this + 0x390) = 0;
    DestroyInstance(*(int *)((int)this + 0x3a8));
    Ov107_ActionResource_Destroy(*(int *)((int)this + 0x470));
    for (i = 0; i < 6; i++) {
        int slot = ((struct row8 *)this)[i + 0x91].a;
        if (slot != 0) {
            DestroyInstance(slot);
        }
    }
    Ov107_DestroyObject((int)this);
}

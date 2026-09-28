struct row8 { int a, b; };

extern void DestroyInstance(int instance);
extern void Ov107_ActionResource_Destroy(int p);
extern void Ov107_DestroyObject(int obj);

// Teardown: destroy the primary sub-object (this[0x388]), release the channel
// (this[0x398]), free the 4 optional slot instances (this + i*8 + 0x39c), then
// notify the owner.
void Ov240_ReleaseSubObjectsAndSlotsThenNotify(int *this)
{
    int i;
    DestroyInstance(*(int *)((int)this + 0x388));
    Ov107_ActionResource_Destroy(*(int *)((int)this + 0x398));
    for (i = 0; i < 5; i++) {
        int slot = ((struct row8 *)this)[i + 0x73].b;
        if (slot != 0) {
            DestroyInstance(slot);
        }
    }
    Ov107_DestroyObject((int)this);
}

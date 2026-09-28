extern void NNS_G3dRenderObjRemoveAnmObj(void *tracks, int handle);
extern void BindAnimTrack(void *anim, unsigned short slot, void *block, short arg);
extern int *Anim_SetFrameWrapped(void *anim, unsigned short slot, int arg);

struct Ov022Rig {
    char _pad0[0x28];
    char anim[0x34 - 0x28];
    int slots[5];
    char tracks[0x108 - 0x48];
    char block[0x130 - 0x108];
    int pShared;
};

void Ov022_ReleaseRigSlots(struct Ov022Rig *obj, int arg1) {
    unsigned int i = 0;

    do {
        if (obj->pShared != 0) {
            int slot = obj->slots[i];
            if (slot != 0) {
                NNS_G3dRenderObjRemoveAnmObj(obj->tracks, slot);
                obj->slots[i] = 0;
            }
            BindAnimTrack(obj->anim, i, (void *)obj->pShared, (short)arg1);
        } else {
            BindAnimTrack(obj->anim, i, obj->block, (short)arg1);
        }
        Anim_SetFrameWrapped(obj->anim, i, 0);
        i = i + 1;
    } while ((int)i < 5);
}

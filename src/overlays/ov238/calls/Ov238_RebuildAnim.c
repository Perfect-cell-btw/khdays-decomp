/* Rebuild the ov238 actor's two-part animation for its current kind (+0x310): the kind is recorded in
 * the front (+0x390, below 0x16) or back (+0x391) slot byte and that part's frame is sampled from the
 * +0x388 rig's +0x88 bank (track 3 / 0); bound slots are released, the bank resets and each live
 * part binds its model record (020c9440: kind + 1, back part 0x12). The current part plays on its
 * track with the +0x311 loop bit, and the other live part resumes at the sampled frame. */
typedef unsigned char u8;
typedef struct { u8 b0 : 1; } Bit0;
typedef struct { char pad0[0xc]; int bound; char pad10[0x14]; } AnimSlot;
struct Ov238Rig { char pad[0x394]; AnimSlot slots[2]; };

extern int Anim_GetFrame(int bank, int track);
extern void FreeAllResourceTables(AnimSlot *slot);
extern void NNS_G3dRenderObjInit(int a, int b);
extern void *Ov107_PackTextureHandle(char *actor, int index);
extern void Snd_RegisterSeqAndBind(AnimSlot *slot, int bank, void *record, int d);
extern void MainBlob_ResetSlotRows(int rig, AnimSlot *slot);
extern void SetSubitemState(int rig, int channel, int a, int b);
extern void Anim_SetFrameWrapped(int bank, int track, int frame);
extern void RefreshObjectCallbacks(int rig, int a);

void Ov238_RebuildAnim(char *actor)
{
    signed char kind = *(signed char *)(actor + 0x310);
    int bank = *(int *)(*(int *)(actor + 0x388) + 0x88);
    int frame;
    int i;
    signed char k;

    if (kind < 0x16) {
        *(signed char *)(actor + 0x390) = kind;
        frame = Anim_GetFrame(bank, 3);
    } else {
        *(signed char *)(actor + 0x391) = kind;
        frame = Anim_GetFrame(bank, 0);
    }
    for (i = 0; i < 2; i++) {
        if (((struct Ov238Rig *)actor)->slots[i].bound != 0) {
            FreeAllResourceTables(&((struct Ov238Rig *)actor)->slots[i]);
        }
    }
    NNS_G3dRenderObjInit(bank + 0x20, *(int *)(bank + 0x78));
    for (i = 0; i < 2; i++) {
        k = *(signed char *)(actor + i + 0x390);
        if (k >= 0) {
            Snd_RegisterSeqAndBind(&((struct Ov238Rig *)actor)->slots[i], bank,
                          Ov107_PackTextureHandle(actor, k < 0x16 ? k + 1 : 0x12), 0xc);
        }
    }
    if (*(signed char *)(actor + 0x310) == 0x16) {
        MainBlob_ResetSlotRows(*(int *)(actor + 0x388), &((struct Ov238Rig *)actor)->slots[1]);
        SetSubitemState(*(int *)(actor + 0x388), 3, 0, ((Bit0 *)(actor + 0x311))->b0);
        if (*(signed char *)(actor + 0x390) >= 0) {
            *(AnimSlot **)(*(int *)(actor + 0x388) + 0x8c) = &((struct Ov238Rig *)actor)->slots[0];
            SetSubitemState(*(int *)(actor + 0x388), 0, 0, *(u8 *)(*(int *)(actor + 0x388) + 0xa8));
            Anim_SetFrameWrapped(bank, 0, frame);
        }
    } else {
        MainBlob_ResetSlotRows(*(int *)(actor + 0x388), &((struct Ov238Rig *)actor)->slots[0]);
        SetSubitemState(*(int *)(actor + 0x388), 0, 0, ((Bit0 *)(actor + 0x311))->b0);
        if (*(signed char *)(actor + 0x391) >= 0) {
            *(AnimSlot **)(*(int *)(actor + 0x388) + 0x8c) = &((struct Ov238Rig *)actor)->slots[1];
            SetSubitemState(*(int *)(actor + 0x388), 3, 0, *(u8 *)(*(int *)(actor + 0x388) + 0xab));
            Anim_SetFrameWrapped(bank, 3, frame);
        }
    }
    RefreshObjectCallbacks(*(int *)(actor + 0x388), 0);
}

extern int Session_GetLocalPlayerIndex(void);
extern int QueryActiveStateOrDelegate(void);
extern int Ov022_GetEntryField66(int nState);
extern int Ov002_GetSlotTableByte(int nSlot);
extern void PlaySoundChecked(int nBank, int nSound);
extern void Slot_Spawn(int nBank, int nSound, void *pPos, int nOwner);

/* Play the sound a slot action makes.
 *
 * The bank offset is the actor's own index times seven, so each actor has its
 * own run of seven action sounds and the action kind picks which of them:
 * kinds 0 and 1 share one, 2 and 3 have their own, and anything else falls to
 * a common one. Kind 0xf is not part of that run at all - it takes a fixed
 * sound and drops the per actor offset entirely.
 *
 * The local seat's own actor plays it flat, unless bit 16 of its flag word is
 * up. Anyone else's plays it positionally from +0x48c, and only when their
 * slot table byte matches the one the active state resolves to.
 *
 * The bank is written into nBank inside the guard rather than passed as a
 * literal, which is what keeps it out of the way of the flag word's register
 * and lets it fill the load's delay slot; the pragma is what stops that store
 * from being propagated back into the call.
 */
#pragma opt_dead_assignments off

void Ov002_PlaySlotActionSound(int pOwner, int nKind)
{
    char *pActor;
    int nBase;
    int nSound;
    int nSlot;
    int nOther;
    int nBank;

    pActor = *(char **)(pOwner + 0x18c);
    nBase = *(unsigned char *)(pActor + 9) * 7;

    switch (nKind) {
    case 0:
    case 1:
        nSound = 0xe;
        break;
    case 2:
        nSound = 0xb;
        break;
    case 3:
        nSound = 0xd;
        break;
    case 0xf:
        nSound = 0x3e;
        nBase = 0;
        break;
    default:
        nSound = 0xc;
        break;
    }

    if (*(unsigned char *)(pActor + 8) == Session_GetLocalPlayerIndex()
            && (nBank = 0, *(int *)pActor & 0x10000) == 0) {
        PlaySoundChecked(nBank, nSound + nBase);
        return;
    }

    nSlot = Ov002_GetSlotTableByte(*(short *)(pActor + 0x66));
    nOther = Ov002_GetSlotTableByte(Ov022_GetEntryField66(QueryActiveStateOrDelegate()));
    if (nOther == nSlot) {
        Slot_Spawn(0, nSound + nBase, pActor + 0x48c, 0);
    }
}

#pragma opt_dead_assignments on

typedef unsigned short u16;

typedef struct {
    int nX;
    int nY;
    int nZ;
} Vec3;

extern int Ov002_LookupChannelEntry(void *pName);
extern void Entity_Register(char *pObj, int nRes, int a, int b);
extern void Actor_SetVecAndSyncChild(char *pNode, Vec3 *pPos);
extern int GameState_GetField(u16 nId, unsigned char nSlot);
extern void Ov002_ElementRefreshNamedBindings(char *pElement);
extern void Ov002_RebindAnimTracks(short *pAnim, int nBlend, int nFrame);
extern void SceneNode_Disable(u16 *pNode);
extern void Obj_SetFlagBit3(char *pObj, int bOn);
extern void Res_RequestIdPair(int nId);

/* Rebuild everything an element shows after its model has been rebound.
 *
 * The two cached vectors are read first because binding the model overwrites
 * the second one, which is put back straight after. The node is then moved to
 * the cached position, the first placement remembers the angle, the game-state
 * bit is re-read and the mode derived from it, the named bindings are
 * re-applied and the mode's track blended in. A mode with no track leaves the
 * object hidden. Finally the owner's own id is refreshed.
 */
void Ov002_ElementRebuildVisuals(char *pElement)
{
    char *pOwner;
    Vec3 vPos;
    Vec3 vSaved;
    u16 wAngle;
    unsigned int nState;
    signed char nTrack;

    pOwner = *(char **)(pElement + 8);
    vPos = *(Vec3 *)(pElement + 0xd0);
    vSaved = *(Vec3 *)(pElement + 0xdc);

    if (*(signed char *)(pOwner + 0x58) != 0) {
        Entity_Register(pElement + 0x1c, Ov002_LookupChannelEntry(pOwner + 0x58),
                      1, 4);
        *(Vec3 *)(pElement + 0xdc) = vSaved;
    }

    Actor_SetVecAndSyncChild(pElement + 0x28, &vPos);

    wAngle = *(u16 *)(pElement + 0x18);
    if ((*(int *)(pElement + 0x28) & 0x20) == 0) {
        *(u16 *)(pElement + 0xa8) = wAngle;
        *(u16 *)(pElement + 0x2c) |= 0x20;
    }

    nState = ((unsigned int)(GameState_GetField(*(u16 *)(pElement + 0x14),
                                           *(unsigned char *)(pElement + 0x16))
                             & 0xfffe) << 15) >> 16;
    /* One mutated index, not two constants: 0x1c2 is past the THUMB immediate
     * range so it lives in a register, and 0x1ce is reached by adding 0xc to
     * it. Naming 0x1ce any other way reloads a second pool word. */
    {
        int off = 0x1c2;

        pElement[off] = (char)(nState & 1);
        if (*(unsigned char *)(pElement + off) == 1) {
            off = off + 0xc;
            pElement[off] = 0;
        } else {
            off = off + 0xc;
            pElement[off] = 2;
        }
    }

    Ov002_ElementRefreshNamedBindings(pElement);

    if (*(signed char *)(pOwner + 0x58) != 0) {
        Ov002_RebindAnimTracks((short *)(pElement + 0x2c),
                            *(signed char *)(pElement + 0x1c3
                                + *(signed char *)(pElement + 0x1ce)), 0);
    }

    if (*(signed char *)(pOwner + 0x58) != 0) {
        nTrack = *(signed char *)(pElement + 0x1c3
                                  + *(signed char *)(pElement + 0x1ce));
        if (nTrack >= 0) {
            SceneNode_Disable((u16 *)(pElement + 0x2c));
            Obj_SetFlagBit3(pElement + 0x1c,
                          (GameState_GetField(*(u16 *)(pElement + 0x14),
                                         *(unsigned char *)(pElement + 0x16))
                           & 1) != 0);
        } else {
            Obj_SetFlagBit3(pElement + 0x1c, 0);
        }
    }

    if (*(short *)(pOwner + 0x68) >= 0) {
        Res_RequestIdPair(*(short *)(pOwner + 0x68));
    }
}

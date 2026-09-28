typedef unsigned short u16;

extern void Ov002_RebindAnimTracks(short *pAnim, int nBlend, int nFrame);
extern void SceneNode_Disable(u16 *pNode);
extern int GameState_GetField(u16 nId, unsigned char nSlot);
extern void Obj_SetFlagBit3(char *pObj, int bOn);
extern void Slot_Spawn(int nA, int nB, char *pDst, int nFlag);

/* Put a timed element into its finishing phase.
 *
 * Stamps the phase, remembers which mode ended it and clears the elapsed
 * counter. When the owner allows it and the element is driving its table, the
 * track that mode selects is blended in from frame zero and the object follows
 * the game-state bit again - unless the mode has no track, in which case the
 * object is simply hidden.
 *
 * Finally, modes 3 and 1 each hand their own pair of owner ids to the fade.
 */
void Ov002_ElementFinishWithMode(char *pElement, unsigned char bMode)
{
    char *pOwner;
    signed char nTrack;
    int nState;
    short nA;
    short nB;

    pOwner = *(char **)(pElement + 8);

    *(unsigned char *)(pElement + 0x1c1) = 2;
    *(unsigned char *)(pElement + 0x1ce) = bMode;
    *(int *)(pElement + 0x1d0) = 0;

    if (*(signed char *)(pOwner + 0x58) != 0 &&
        (*(u16 *)(pElement + 0x12) & 4) != 0) {

        nTrack = *(signed char *)(pElement + 0x1c3
                                  + *(signed char *)(pElement + 0x1ce));
        if (nTrack != -1) {
            Ov002_RebindAnimTracks((short *)(pElement + 0x2c), nTrack, 0);
            SceneNode_Disable((u16 *)(pElement + 0x2c));
            nState = GameState_GetField(*(u16 *)(pElement + 0x14),
                                   *(unsigned char *)(pElement + 0x16));
            Obj_SetFlagBit3(pElement + 0x1c, (nState & 1) != 0);
        } else {
            Obj_SetFlagBit3(pElement + 0x1c, 0);
        }
    }

    nA = *(short *)(pOwner + 0x68);
    if (nA >= 0) {
        if (*(signed char *)(pElement + 0x1ce) == 3) {
            nB = *(short *)(pOwner + 0x6a);
            if (nB >= 0) {
                Slot_Spawn(nA, nB, pElement + 0xd0, 0);
            }
        } else if (*(signed char *)(pElement + 0x1ce) == 1) {
            nB = *(short *)(pOwner + 0x6c);
            if (nB >= 0) {
                Slot_Spawn(nA, nB, pElement + 0xd0, 0);
            }
        }
    }
}

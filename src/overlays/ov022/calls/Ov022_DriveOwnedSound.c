/* ov022: hand a pair of ids to the sound side, one way or the other.
 *
 * A positive direction starts them, a negative one stops them, and zero does
 * nothing at all. Either way the pair is put on the stack first, because both
 * of the calls that take it want its address.
 *
 * The sound side is only told when this object owns the active channel. On the
 * stopping path there is one more turn: if the event flag is set the stop gets
 * its own handler, otherwise the default one runs with zero.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

#define STOP_EVENT_ID 0x37c5

struct Owner {
    u8 pad00[8];
    u8 nChannel;                 /* 0x08 */
    u8 nHandle;                  /* 0x09 */
};

extern int Session_GetLocalPlayerIndex(void);
extern void Ov002_PanelAddSubEntryAndRepaint(u16 nFirst, u16 nSecond);
extern void Ov002_RemoveEntryAndReopen(u16 nFirst, u16 nSecond);
extern void Ov002_RefreshMemberPanel(void);
extern void Ov002_AcceptRequestAndNotify(int nMode);
extern int GameState_GetField(int nEvent, int nFlag);
extern void func_020359b4(int nHandle, u16 *pPair);
extern void Slot_ClearMatchingEntry(int nHandle, u16 *pPair);

void Ov022_DriveOwnedSound(struct Owner *pOwner, int nSecond, int nFirst,
                         int nDir)
{
    u16 aPair[2];

    aPair[1] = (u16)nSecond;
    aPair[0] = (u16)nFirst;
    if (nDir > 0) {
        if (pOwner->nChannel == Session_GetLocalPlayerIndex()) {
            Ov002_PanelAddSubEntryAndRepaint(nFirst, nSecond);
        }
        func_020359b4(pOwner->nHandle, aPair);
    } else if (nDir < 0) {
        if (pOwner->nChannel == Session_GetLocalPlayerIndex()) {
            Ov002_RemoveEntryAndReopen(nFirst, nSecond);
            if (GameState_GetField(STOP_EVENT_ID, 1) == 0) {
                Ov002_AcceptRequestAndNotify(0);
            } else {
                Ov002_RefreshMemberPanel();
            }
        }
        Slot_ClearMatchingEntry(pOwner->nHandle, aPair);
    }
}

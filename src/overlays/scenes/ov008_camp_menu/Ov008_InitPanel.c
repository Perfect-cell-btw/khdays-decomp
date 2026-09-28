/* Ov008_InitPanel -- Ov008_InitPanel (128 B, 8 relocs).
 * Binds arg0 as the active menu panel (data_ov008_02090f1c) and copies a resource handle into
 * the caller's out-param. Session_GetLocalPlayerIndex() yields a token that Slot4_GetIfOccupied() resolves to a
 * record; its field +4 is written to *arg1 and mirrored (as u16) into field +4 of the object
 * from Ov008_GetSharedRecord(). Then Ov008_PrimeSubSceneFromCursor(0) runs, and when Ov008_IsSessionReady()
 * reports active it fires cue 0x200a (GameState_IsFlagSet) and Ov008_SetBusyFlag(). Finally it
 * clears the panel's field 0x5c8 (= -1) and sets bit 0x100 in the u16 flags at 0x5c6.
 * (Session_GetLocalPlayerIndex's result must stay live into Slot4_GetIfOccupied, which is why the panel-pointer
 * store lands between the two calls.) */

#include "nitro/types.h"

extern void *data_ov008_02090f1c;
extern int   Session_GetLocalPlayerIndex(void);
extern void *Slot4_GetIfOccupied(unsigned int a);
extern void *Ov008_GetSharedRecord(void);
extern void  Ov008_PrimeSubSceneFromCursor(int a);
extern int   Ov008_IsSessionReady(void);
extern int GameState_IsFlagSet(int flag);
extern void  Ov008_SetBusyFlag(int);

void Ov008_InitPanel(void *arg0, int *arg1)
{
    int a = Session_GetLocalPlayerIndex();
    data_ov008_02090f1c = arg0;
    *arg1 = *(int *)((char *)Slot4_GetIfOccupied((unsigned int)a) + 4);
    *(u16 *)((char *)Ov008_GetSharedRecord() + 4) = *arg1;
    Ov008_PrimeSubSceneFromCursor(0);
    if (Ov008_IsSessionReady() != 0) {
        Ov008_SetBusyFlag(GameState_IsFlagSet(0x200a));
    }
    *(int *)((char *)data_ov008_02090f1c + 0x5c8) = -1;
    *(u16 *)((char *)data_ov008_02090f1c + 0x5c6) |= 0x100;
}

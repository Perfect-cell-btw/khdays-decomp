/*
 * Game_UnwindActionStack - pre-tick cleanup/unwind for the gameplay action system, run first from
 * Game_RunActionScript when the entry stack has grown past its saved depth. st is the action-system
 * state (0x48-byte Entry array at st+4, current-depth counter st+0x124, saved depth st+0x580).
 *
 * On the current entry (cur = &entries[count]): when a specific mode is active
 * (LoadGlobalIntAtC()==2, LoadGlobalU16At0() bit 2, LoadGlobalPtr4FieldDcOrZero(), !Ov002_GetPanelField018c()) it pings
 * Ov002_Hud_HidePanel(). Then it fires each of the five callback slots and the action slot whose
 * handler is one of the two cancel sentinels (Game_ActionTurnHandler / DispatchTrackEntryIfReady) via
 * Loader_WaitAndReleaseSlot(st, arg), clearing every slot. Finally it pops entries from the current depth down
 * to the saved depth st+0x580 (subtracting each popped entry's +4 field from the running total at
 * st+0), sets the depth to the saved depth, copies st+0x584 into that entry's +0x10 field, and
 * clears st+0x584/st+0x588.
 *
 * THUMB. The callback-slot cancel test is written fall-through-first (call when the slot handler is
 * the sentinel OR the action handler is the other sentinel); the depth counter is read once into a
 * local so the pop loop reuses it; and the final field store addresses entries[depth]+0x10 as
 * st + depth*0x48 + 0x14 (the compiler folds the +4 base into the offset).
 */

#include "nitro/types.h"
typedef int (*Fn)(void *st, int arg);

extern int  LoadGlobalIntAtC(void);
extern int  LoadGlobalU16At0(void);
extern int  LoadGlobalPtr4FieldDcOrZero(void);
extern int  Ov002_GetPanelField018c(void);
extern void Ov002_Hud_HidePanel(void);
extern void Loader_WaitAndReleaseSlot(void *st, int arg);
extern void Game_ActionTurnHandler(void);
extern void DispatchTrackEntryIfReady(void);

void Game_UnwindActionStack(char *st)
{
    char *cur;
    char *e;
    int i;

    cur = st + 4 + *(int *)(st + 0x124) * 0x48;
    if (LoadGlobalIntAtC() == 2 && (LoadGlobalU16At0() & 4) != 0
        && LoadGlobalPtr4FieldDcOrZero() != 0 && Ov002_GetPanelField018c() == 0) {
        Ov002_Hud_HidePanel();
    }
    for (i = 0, e = cur; i < 5; i++, e += 8) {
        Fn f = *(Fn *)(e + 0x20);
        if (f != 0) {
            if (f == (Fn)Game_ActionTurnHandler || *(Fn *)(cur + 0x18) == (Fn)DispatchTrackEntryIfReady) {
                Loader_WaitAndReleaseSlot(st, *(int *)(e + 0x24));
            }
            *(int *)(e + 0x20) = 0;
            *(int *)(e + 0x24) = 0;
        }
    }
    {
        Fn af = *(Fn *)(cur + 0x18);
        if (af != 0) {
            if (af == (Fn)Game_ActionTurnHandler || af == (Fn)DispatchTrackEntryIfReady) {
                Loader_WaitAndReleaseSlot(st, *(int *)(cur + 0x1c));
            }
            *(int *)(cur + 0x18) = 0;
        }
    }
    {
        int count = *(int *)(st + 0x124);
        if (count > *(int *)(st + 0x580)) {
            char *e2 = st + 4 + count * 0x48;
            do {
                *(int *)st = *(int *)st - *(int *)(e2 + 4);
                count--;
                e2 -= 0x48;
            } while (count > *(int *)(st + 0x580));
        }
    }
    *(int *)(st + 0x124) = *(int *)(st + 0x580);
    {
        char *e3 = st + 4 + *(int *)(st + 0x124) * 0x48;
        *(int *)(e3 + 0x10) = *(int *)(st + 0x584);
    }
    *(int *)(st + 0x588) = 0;
    *(int *)(st + 0x584) = 0;
}

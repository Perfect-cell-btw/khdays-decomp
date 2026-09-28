/* Tear the HUD down if the panel is in state 4, and report whether it happened.
 *
 * With no context there is nothing to dismiss, so the caller's own value comes straight back out.
 * Otherwise the entry named by the key at 0x69c is selected, and a panel sitting in state 4 is
 * torn down with the cancel sound before the key at 0x6a0 is selected instead.
 *
 * Three details carry the original codegen. The caller's value is returned by an early return
 * rather than through the result variable, so the original never has to save r0. The state test
 * is written not-equal, leaving the dismissal arm out of line. And the result is initialised to
 * one where it is declared, ahead of the null check, with only the not-equal arm clearing it.
 */

#include "nitro/types.h"

extern char *data_ov002_0207f624;
extern void Ov002_SelectEntryByKey(int key);
extern long long Ov002_FillMapRows(int a, int b, int c, int d, int e);
extern void Ov002_HudTeardownToState5(long long value);
extern void PlaySound(int a, int b);

u32 Ov002_DismissIfState4(u32 fallback) {
    u32 result = 1;
    char *ctx = data_ov002_0207f624;

    if (ctx == 0) {
        return fallback;
    }
    Ov002_SelectEntryByKey(*(int *)(ctx + 0x69c));
    if (*(int *)ctx != 4) {
        result = 0;
    } else {
        Ov002_HudTeardownToState5(Ov002_FillMapRows(9, 0, 0, 0x20, 0x18));
        PlaySound(0, 10);
    }
    Ov002_SelectEntryByKey(*(int *)(ctx + 0x6a0));
    return result;
}

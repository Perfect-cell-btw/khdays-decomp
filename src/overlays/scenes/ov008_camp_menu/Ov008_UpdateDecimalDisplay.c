/* Draws a decimal value with digit glyph entries, right to left from the given width, clamped to
 * the maximum and to zero. */

#include "nitro/types.h"

extern void *Ov008_GetCtxBlock9500(void);
extern void *Ov008_FindEntryByTag(void *context, u16 tag);
extern void Ov008_ApplyTempFieldsAndRestore(void *context, void *entry,
                                int value, int subId);

void
Ov008_UpdateDecimalDisplay(int group, int value, int maximum,
                    int width, int subId)
{
    void *context = (void *)*(volatile int *)&subId;
    int subIdValue = (int)context;
    void *entry;
    int digit;

    context = Ov008_GetCtxBlock9500();
    if (value <= maximum) {
        if (value < 0) {
            value = 0;
        }
        maximum = value;
    }

    do {
        digit = maximum % 10;
        maximum = maximum / 10;
        entry = Ov008_FindEntryByTag(context, (u16)(group + digit));
        Ov008_ApplyTempFieldsAndRestore(context, entry, (s16)width--,
                            (s16)subIdValue);
        if (width < 0) {
            return;
        }
    } while (maximum > 0);
}

/* Run ReleaseField74AndCleanup over the 6+1 sub-object slots (base=*data_ov033_020b4b80+0x2c2c
 * +0xc, then 6x stride 0x110) of the global object. x4 ov033/051/071/089. */

#include "game/engine.h"

extern void *data_ov089_020bc120;

void Ov089_refreshSubObjectSlots(void)
{
    char *base = (char *)*(int *)&data_ov089_020bc120 + 0x2c2c;
    int i;
    char *p;
    ReleaseField74AndCleanup(base + 0xc);
    p = base + 0x120;
    i = 0;
    do {
        ReleaseField74AndCleanup(p);
        i++;
        p += 0x110;
    } while (i < 6);
}

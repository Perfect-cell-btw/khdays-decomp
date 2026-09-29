/* Releases the shop's model resources. */

#include "game/engine.h"

extern char *data_ov008_02090fac;
void Ov008_Shop_ReleaseModel(void)
{
    ReleaseField74AndCleanup(data_ov008_02090fac + 0xbff0);
}

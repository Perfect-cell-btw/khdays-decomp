#include "game/ov008_camp_menu.h"
/* Polls the link service instance. Returns the word it reads at +0x28 of the object. */

extern int Obj_GetWord28(int);
int Ov008_Link_Poll(void)
{
    return Obj_GetWord28((int)data_ov008_02090f24.pController);
}

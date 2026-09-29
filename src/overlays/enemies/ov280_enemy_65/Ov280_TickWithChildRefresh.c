/* Refreshes the child selector at +0x388, then runs the object tick. */

#include "game/enemy_common.h"

extern int Ov107_ProcessObjectTick();

struct S { char pad[0x388]; int field_388; };

int Ov280_TickWithChildRefresh(struct S *a, int b) {
    Ov107_RefreshAndSelectChild(a->field_388, b);
    return Ov107_ProcessObjectTick(a, b);
}

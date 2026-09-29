/* Refreshes the child selector and runs the tick, then rebuilds the marker transform (+0x39c) at
 * +0x394's position with the object's rotation. */

#include "game/enemy_common.h"

extern int Ov107_ProcessObjectTick();
extern int SrtTransform_SetIdentity();
extern int Srt_SetTranslation();
extern int Srt_SetRotationQuat();

void Ov141_TickAndSyncMarkerSrt(char *obj, int arg1) {
    Ov107_RefreshAndSelectChild(*(int *)(obj + 0x3cc), arg1);
    Ov107_ProcessObjectTick(obj, arg1);
    SrtTransform_SetIdentity(obj + 0x39c);
    Srt_SetTranslation(obj + 0x39c, *(int *)(obj + 0x394) + 0x14);
    Srt_SetRotationQuat(obj + 0x39c, obj + 0xa0);
}

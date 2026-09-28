/* Update of the ov256 model: +0x460 takes the body's (+0x384) current frame on track 0; while the body
 * animates (+0xad) its track-0 frame and the +0x3ac part's are clamped to +0x460 plus the +0x45c
 * offset (x 512). Then the +0x450 part and the base update run. */

#include "nitro/types.h"

extern int queryTableEntry(int model, int track);
extern int Obj_GetCellScaledField(int model, int track, int a);
extern void callIfTableEntrySet(int model, int track, int frame);
extern void Ov107_RefreshAndSelectChild(int part, int arg);
extern void Ov107_ProcessObjectTick(char *self, int arg);

void Ov256_ModelUpdate(char *self, int arg)
{
    *(int *)(self + 0x460) = queryTableEntry(*(int *)(self + 0x384), 0);
    if (*(u8 *)(*(int *)(self + 0x384) + 0xad) != 0) {
        int frame = Obj_GetCellScaledField(*(int *)(self + 0x384), 0, 0);

        if (frame > *(int *)(self + 0x460) + (*(int *)(self + 0x45c) << 9)) {
            callIfTableEntrySet(*(int *)(self + 0x384), 0, *(int *)(self + 0x460) + (*(int *)(self + 0x45c) << 9));
            callIfTableEntrySet(*(int *)(self + 0x3ac), 0, *(int *)(self + 0x460) + (*(int *)(self + 0x45c) << 9));
        } else {
            callIfTableEntrySet(*(int *)(self + 0x384), 0, frame);
            callIfTableEntrySet(*(int *)(self + 0x3ac), 0, frame);
        }
    }
    Ov107_RefreshAndSelectChild(*(int *)(self + 0x450), arg);
    Ov107_ProcessObjectTick(self, arg);
}

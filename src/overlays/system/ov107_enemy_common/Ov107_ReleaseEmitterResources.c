#include "game/enemy_common.h"

extern void DestroyInstance(int h);
extern void NNSi_FndDestroyDoubleList(char *list);

/* Releases the emitter's two own sprites and the four per-slot ones, then its three lists. */
void Ov107_ReleaseEmitterResources(char *self) {
    int i;
    DestroyInstance(*(int *)(self + 0x100));
    DestroyInstance(*(int *)(self + 0x104));
    for (i = 0; i < 4; i++) {
        DestroyInstance(*(int *)(self + i * sizeof(int) + 0x108));
    }
    NNSi_FndDestroyDoubleList(self + 0x80);
    NNSi_FndDestroyDoubleList(self + 0xa8);
    NNSi_FndDestroyDoubleList(self + 0xd0);
    Ov107_Region_Destroy(self);
}

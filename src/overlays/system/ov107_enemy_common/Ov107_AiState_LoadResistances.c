/* Loads the five resistance triples (percent) of the actor kind. */

#include "nitro/types.h"
#include "game/enemy_common.h"

extern void *Archive_LoadFile(u32 flags, int heap);
extern int func_02020400(int value, int percent);
extern void NNSi_FndFreeFromDefaultHeap(void *p);

void Ov107_AiState_LoadResistances(char *self, u32 mask) {
    int ctx = func_ov107_020c9848();
    u32 table = *(u32 *)(ctx + 0x84);
    u32 flags = (((table + 0x8000) & 0xfffffc) << 7) | 0x80000000u | (((u32)0xfffffc >> 15) & mask);
    char *allocBase = (char *)Archive_LoadFile(flags, 0xb);
    char *src = allocBase;
    int i;
    char buf[8];
    for (i = 0; i < 5; i++) {
        *(u16 *)(buf + 6) = *(u16 *)(src + 0);
        *(int *)(self + 0x314) = func_02020400((int)*(s16 *)(buf + 6) << 4, 100);
        *(u16 *)(buf + 4) = *(u16 *)(src + 2);
        *(int *)(self + 0x318) = func_02020400((int)*(s16 *)(buf + 4) << 4, 100);
        *(u16 *)(buf + 0) = *(u16 *)(src + 4);
        *(u16 *)(buf + 2) = *(u16 *)(src + 4);
        src += 6;
        *(int *)(self + 0x31c) = func_02020400((int)*(s16 *)(buf + 2) << 4, 100);
        self += 0xc;
    }
    NNSi_FndFreeFromDefaultHeap(allocBase);
}

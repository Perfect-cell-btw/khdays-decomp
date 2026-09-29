/*
 * Ov208_MessageMapTableForward -- x3. Message handler: map the message kind through a 15-entry table and
 * forward. A local copy of the const table (data_020d4798) is indexed by kind; the result feeds
 * 020c9440(self, table[kind]), whose handle goes to 020d0628(*(self+0x384), handle, arg3, self+0x388).
 * Finish with a reset (0203c7ac).
 */

#include "game/enemy_common.h"

struct t15 { int w[15]; };
extern void Ov208_BindClip(int a, int b, int c, int d);
extern void RefreshObjectCallbacks(int a, int b);
extern struct t15 data_ov208_020d4798;

void Ov208_MessageMapTableForward(int self, int kind, int arg3) {
    struct t15 table = data_ov208_020d4798;

    Ov208_BindClip(*(int *)(self + 0x384), Ov107_PackTextureHandle((char *)self, table.w[kind]), arg3,
                        self + 0x388);
    RefreshObjectCallbacks(*(int *)(self + 0x384), 0);
}

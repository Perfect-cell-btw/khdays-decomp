/* Commits the widget scroll for the frame and, outside mode 0x2a, feeds both stream groups
 * (flagging the local player when idle). */

#include "nitro/types.h"

struct Part { int header; u16 flags; };
struct StreamGroup { u8 bytes[0x30]; };
struct Scroll { u8 bytes[8]; };
struct Widget { u8 bytes[8]; };
struct Runtime {
    u8 pad000[0x20];
    struct Part *part20;
    u8 pad024[0x440];
    u64 flags464;
    u64 flags46c;
    u8 pad474[0xa98];
    struct Widget widgetf0c;
    u8 padf14[0x1730];
    struct StreamGroup *groups2644;
    u8 pad2648[0x472];
    short row2aba;
    u8 pad2abc[0x194];
    struct Scroll scroll2c50;
};
extern struct Runtime *data_ov035_020b4ca0;
extern int Anim_GetFrame(u16 *, int);
extern int LoadGlobalU16At0(void);
extern unsigned int Session_GetLocalPlayerIndex(void);
extern void Ov002_WidgetScrollCommit(struct Widget *, struct Scroll *, int, int);
extern int Ov022_GetGlobal34(void);
extern void Ov022_ForwardToNodeHandler(struct StreamGroup *, int);
extern void Ov022_InvokeCallback24IfBit0(struct StreamGroup *);
extern int Ov022_AreStreamsIdle(struct StreamGroup *);
extern int func_ov022_020ad588(struct Runtime *);

int Ov035_Weapon_TickStreams(struct Runtime *self)
{
    struct Runtime *base = data_ov035_020b4ca0;
    int row = Anim_GetFrame(&self->part20->flags, 0);
    Ov002_WidgetScrollCommit(&self->widgetf0c, &base->scroll2c50, self->row2aba, row);
    if (LoadGlobalU16At0() != 0x2a) {
        int i;
        for (i = 0; i < 2; i++) {
            Ov022_ForwardToNodeHandler(&self->groups2644[i], Ov022_GetGlobal34());
            Ov022_InvokeCallback24IfBit0(&self->groups2644[i]);
        }
        if (Ov022_AreStreamsIdle(&self->groups2644[0]) == 0 ||
            Ov022_AreStreamsIdle(&self->groups2644[1]) == 0) {
            if (Session_GetLocalPlayerIndex() == 0) self->flags464 |= 0x10000;
            if (Session_GetLocalPlayerIndex() == 0) self->flags46c |= 0x10000;
        }
    }
    return func_ov022_020ad588(base);
}

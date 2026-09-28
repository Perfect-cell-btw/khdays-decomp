/* Moves the reward list selection with the D-pad, playing the move sound, and refreshes the
 * indicators; returns whether it moved. */

#include "nitro/types.h"

typedef struct MenuLimitHeader { u16 inputMask; short limits[2]; char opaque[20]; } MenuLimitHeader;
typedef struct Ov005Context { char opaque00[0x4c12]; MenuLimitHeader menuLimitHeader; } Ov005Context;
extern Ov005Context *data_ov005_0205b80c;
extern u16 Mem_ReadU16(MenuLimitHeader *);
extern int Ov005_MoveSelection(int);
extern void PlaySound(int,int);
extern void Ov005_RefreshSelectionIndicators(void);
int Ov005_HandleDirectionalInput(void) {
    int direction;
    int changed;
    /* The target leaves r4 unchanged when none of these direction bits is set. */
    if(Mem_ReadU16(&data_ov005_0205b80c->menuLimitHeader)&0x40)direction=0x40;
    if(Mem_ReadU16(&data_ov005_0205b80c->menuLimitHeader)&0x80)direction=0x80;
    if(Mem_ReadU16(&data_ov005_0205b80c->menuLimitHeader)&0x20)direction=0x20;
    if(Mem_ReadU16(&data_ov005_0205b80c->menuLimitHeader)&0x10)direction=0x10;
    changed=Ov005_MoveSelection(direction);
    if(changed)PlaySound(0,0);
    Ov005_RefreshSelectionIndicators();
    return changed;
}

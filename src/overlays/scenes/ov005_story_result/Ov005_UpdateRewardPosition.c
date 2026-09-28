/* Slides the reward multiplier banner with its tween and shows it with the multiplier's frame. */

#include "nitro/types.h"
typedef struct Tween {int mode,duration,from,to;long long startTick;unsigned int flags;} Tween;
typedef struct Ov005Context {char header[0x54];char embeddedManager[0x4a80];char opaque4ad4[0x19c];Tween statusTween;} Ov005Context;
typedef struct Ov005Config {char opaque00[0x68];u8 rewardMultiplier;} Ov005Config;
extern Ov005Context *data_ov005_0205b80c;
extern Ov005Config data_ov005_0205b85c;
extern void Tween_Sample(Tween *,int *);
extern void Ov005_SetEntryOffsetXY(int,short,short);
extern int Ov005_FindEntryById(void *,int);
extern unsigned int Ov005_GetField84Bit1(void *,int);
extern void Ov005_ReleaseTwoSlotsEx_2(void *,int,unsigned int);
extern void Ov005_SetEntrySlotsVisible(void *,int,int);
void Ov005_UpdateRewardPosition(void) {
    int position;
    Ov005Config *config=&data_ov005_0205b85c;
    int slot;
    Tween_Sample(&data_ov005_0205b80c->statusTween,&position);
    Ov005_SetEntryOffsetXY(47,0,position>>12);
    slot=Ov005_FindEntryById(data_ov005_0205b80c->embeddedManager,47);
    if(Ov005_GetField84Bit1(data_ov005_0205b80c->embeddedManager,slot))return;
    slot=Ov005_FindEntryById(data_ov005_0205b80c->embeddedManager,47);
    Ov005_ReleaseTwoSlotsEx_2(data_ov005_0205b80c->embeddedManager,slot,(u8)(config->rewardMultiplier-2));
    slot=Ov005_FindEntryById(data_ov005_0205b80c->embeddedManager,47);
    Ov005_SetEntrySlotsVisible(data_ov005_0205b80c->embeddedManager,slot,1);
}

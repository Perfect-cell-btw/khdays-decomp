/* Set tile and screen bases for the result/menu backgrounds on both engines. */

#include "nitro/types.h"

extern void GXS_SetGraphicsMode(int);
extern void GX_SetGraphicsMode(int,int,int);
void Ov005_ConfigureBackgroundControls(void) {
    volatile u16 *subBg1=(volatile u16 *)0x0400100a;
    volatile u16 *mainBg1=(volatile u16 *)0x0400000a;
    GXS_SetGraphicsMode(0);
    subBg1[0]=(subBg1[0]&0x43)|0x84;
    subBg1[2]=(subBg1[2]&0x43)|0x388;
    *(volatile u16 *)0x04001008=(*(volatile u16 *)0x04001008&0x43)|0x48c;
    subBg1[1]=(subBg1[1]&0x43)|0x590;
    GX_SetGraphicsMode(1,0,1);
    mainBg1[0]=(mainBg1[0]&0x43)|4;
    mainBg1[2]=(mainBg1[2]&0x43)|0x108;
    mainBg1[1]=(mainBg1[1]&0x43)|0x40c;
}

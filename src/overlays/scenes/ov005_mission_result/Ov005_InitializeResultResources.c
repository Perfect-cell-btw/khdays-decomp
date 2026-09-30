/* Initialises the reward menu: allocates its row buffers and textures, loads its text and archives,
 * and sets up the input limits. */

#include "nitro/types.h"

typedef struct Ov005Context {void *resultArchive,*localizedResultArchive;char pad8[0x4bdc];void *rowBuffers[3];char pad4bf0[0x22];char inputHeader[26];char pad4c2c[0x5d550];char menuText[12];} Ov005Context;
extern Ov005Context *data_ov005_0205b80c;
extern unsigned short data_ov005_0205b334[];
extern char gOv005UiSrsltResTextPath[],gOv005UiSrsltResPath[],gOv005UiSrsltResPath_2[];
extern void *NNS_FndAllocFromDefaultExpHeapEx(unsigned int,int);
extern void MIi_CpuClear16(unsigned short,void *,unsigned int);
extern void Ov005_AllocateResultTextures(void);
extern void Ov005_InitResourceRecord(void *,const char *);
extern void *Msg_OpenContainerAndReadHeader(const char *,int);
extern void SetMasterBrightnessMain(int);
extern int Header_InitWithLimits(void *,short *);
void Ov005_InitializeResultResources(void) {
    short limits[2];
    u8 i;
    limits[1]=data_ov005_0205b334[2];
    limits[0]=data_ov005_0205b334[1];
    for(i=0;i<3;i++) {
        data_ov005_0205b80c->rowBuffers[i]=NNS_FndAllocFromDefaultExpHeapEx(0x600,32);
        MIi_CpuClear16(0,data_ov005_0205b80c->rowBuffers[i],0x600);
    }
    Ov005_AllocateResultTextures();
    Ov005_InitResourceRecord(data_ov005_0205b80c->menuText,gOv005UiSrsltResTextPath);
    data_ov005_0205b80c->resultArchive=Msg_OpenContainerAndReadHeader(gOv005UiSrsltResPath,14);
    data_ov005_0205b80c->localizedResultArchive=Msg_OpenContainerAndReadHeader(gOv005UiSrsltResPath_2,14);
    SetMasterBrightnessMain(-16);
    Header_InitWithLimits(data_ov005_0205b80c->inputHeader,limits);
}

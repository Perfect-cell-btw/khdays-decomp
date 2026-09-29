/* Initialises the result screen: allocates its row buffers, resets its tweens, loads its text and
 * archives, and computes the gauge range. */

#include "nitro/types.h"
#include "game/engine.h"

typedef struct Tween {int mode,duration,from,to;long long startTick;unsigned int flags;} Tween;
typedef struct Ov005ResultTween {Tween tween;int value;char unknown20[12];} Ov005ResultTween;
typedef struct Ov005TextTable {void *resource;int count;void *entries;} Ov005TextTable;
typedef struct Ov005Config {char unknown00[0x48];int gaugeScore;char unknown4c[16];u8 bMode;} Ov005Config;
typedef struct Ov005ResultContext {
 void *resultArchive,*localizedResultArchive;char unknown08[0x4b54];
 long long startTick;void *rowBuffers[4];char unknown4b74[16];
 Ov005ResultTween resultTweens[4];char unknown4c34[4];Ov005TextTable menuText;
 char unknown4c44[8];int gaugeMaximum,gaugeValue;
} Ov005ResultContext;
extern Ov005Config data_ov005_0205b85c;
extern Ov005ResultContext *data_ov005_0205b810;
extern char data_ov005_0205b5bc[],data_ov005_0205b5d0[],data_ov005_0205b5e0[];
extern void *NNS_FndAllocFromDefaultExpHeapEx(unsigned int,int);
extern void MIi_CpuClear16(unsigned short,void *,unsigned int);
extern void Tween_Clear(Tween *);
extern void Ov005_InitResourceRecord(Ov005TextTable *,const char *);
extern long long OS_GetTick(void);
extern void *Msg_OpenContainerAndReadHeader(const char *,int);
extern void Ov005_CalculateGaugeRange(int *,int);
void Ov005_InitResultResources(void) {
 u8 i;
 Ov005Config *config=&data_ov005_0205b85c;
 for(i=0;i<4;i++) {
  data_ov005_0205b810->rowBuffers[i]=NNS_FndAllocFromDefaultExpHeapEx(0x600,2);
  MIi_CpuClear16(0,data_ov005_0205b810->rowBuffers[i],0x600);
 }
 for(i=0;i<4;i++) {
  Ov005ResultTween *entry=&data_ov005_0205b810->resultTweens[i];
  Tween_Clear(&entry->tween);
  entry->value=1000;
 }
 Ov005_InitResourceRecord(&data_ov005_0205b810->menuText,data_ov005_0205b5bc);
 data_ov005_0205b810->startTick=OS_GetTick();
 data_ov005_0205b810->resultArchive=Msg_OpenContainerAndReadHeader(data_ov005_0205b5d0,14);
 data_ov005_0205b810->localizedResultArchive=Msg_OpenContainerAndReadHeader(data_ov005_0205b5e0,14);
 SetMasterBrightnessSub(-16);
 data_ov005_0205b810->resultTweens[0].value=0;
 data_ov005_0205b810->resultTweens[3].value=(config->bMode+1)*800;
 Ov005_CalculateGaugeRange(&data_ov005_0205b810->gaugeMaximum,config->gaugeScore);
}

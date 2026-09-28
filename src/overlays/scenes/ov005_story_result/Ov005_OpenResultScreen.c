/* Opens the mission result screen: sets up its resources, graphics, sprites and text, shows the
 * result labels for the scene and draws the result gauge. */

#include "nitro/types.h"
typedef void *(*Ov005ResultState)(void);
typedef struct Ov005Config {u16 sceneId;char unknown02[8];u16 resultLabelIndex,rewardMode;} Ov005Config;
typedef struct Ov005ResultContext {char unknown00[0x4c4c];int gaugeMaximum,gaugeValue;char unknown4c54[16];} Ov005ResultContext;
typedef struct Ov005ResultGaugeRequest {int firstTileId;short column;u16 row;int maximum,value,widthPixels;} Ov005ResultGaugeRequest;
extern Ov005Config data_ov005_0205b85c;
extern Ov005ResultContext *data_ov005_0205b810;
extern Ov005ResultContext *NNSi_FndGetCurrentRootHeap(void);
extern void MI_CpuFill8(void *,unsigned char,u32);
extern void Ov005_InitResultResources(void),Ov005_LoadResultBackgroundGraphics(void),Ov005_InitializeResultResourceTracker(void),Ov005_InitializeMissionResultSprites(void),Ov005_InitializeResultTextSurfaces_2(void);
extern void Ov005_SelectEntryById(u32),Ov005_DrawResultGauge(Ov005ResultGaugeRequest *),Ov005_UpdateResultLabels(void);
extern void *Ov005_TickResultScreen(void);
Ov005ResultState Ov005_OpenResultScreen(void) {
    Ov005Config *config=&data_ov005_0205b85c;
    Ov005ResultGaugeRequest gauge;
    data_ov005_0205b810=NNSi_FndGetCurrentRootHeap();
    MI_CpuFill8(data_ov005_0205b810,0,sizeof(Ov005ResultContext));
    Ov005_InitResultResources();
    Ov005_LoadResultBackgroundGraphics();
    Ov005_InitializeResultResourceTracker();
    Ov005_InitializeMissionResultSprites();
    Ov005_InitializeResultTextSurfaces_2();
    Ov005_SelectEntryById(0x3e9);
    switch(config->sceneId) {
    case 0x547:Ov005_SelectEntryById(0x40f);break;
    case 0x548:Ov005_SelectEntryById(0x410);break;
    case 0x514:case 0x515:Ov005_SelectEntryById(0x412);break;
    case 0x54a:
    default:Ov005_SelectEntryById(config->resultLabelIndex+0x403);break;
    }
    if(config->rewardMode!=255 && config->rewardMode!=2)Ov005_SelectEntryById(0x3ea);
    gauge.firstTileId=0x3fb;
    gauge.column=3;
    gauge.row=21;
    if(data_ov005_0205b810->gaugeMaximum==0) gauge.maximum=gauge.value=100;
    else {
        gauge.maximum=data_ov005_0205b810->gaugeMaximum;
        gauge.value=data_ov005_0205b810->gaugeValue;
    }
    gauge.widthPixels=144;
    Ov005_DrawResultGauge(&gauge);
    Ov005_UpdateResultLabels();
    return Ov005_TickResultScreen;
}

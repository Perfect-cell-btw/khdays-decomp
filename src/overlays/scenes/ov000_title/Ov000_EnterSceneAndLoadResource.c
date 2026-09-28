/* Scene entry: build the context, copy two OPTIONAL u16, create resource 14 at context+0x9660, and
 * return the next callback. Calls Ov000_CreateSceneContext, so +0x9660 is inside that same 0xd18c
 * object. */

#include "nitro/types.h"
typedef void (*OverlayCallback)(void);

typedef struct {
    u16 second_value;
    u16 first_value;
    u8 pad_0004[0x965c];
    u32 resource;
} OverlayContext;

typedef struct {
    u32 first;
    u32 second;
} OverlayStartParams;

extern u8 data_ov000_0205abd0[];
extern OverlayContext *NNSi_FndGetCurrentRootHeap(void);
extern void Ov000_CreateSceneContext(void);
extern void SetMasterBrightnessMain(int value);
extern void SetMasterBrightnessSub(int value);
extern u32 Loader_RequestFile(const void *data, int id);
extern void Ov000_EnterListScene(void);

OverlayCallback Ov000_EnterSceneAndLoadResource(const OverlayStartParams *params) {
    OverlayContext *context = NNSi_FndGetCurrentRootHeap();

    Ov000_CreateSceneContext();
    SetMasterBrightnessMain(-16);
    SetMasterBrightnessSub(-16);

    if (params != 0) {
        context->first_value = params->first;
        context->second_value = params->second;
    }

    context->resource = Loader_RequestFile(data_ov000_0205abd0, 14);
    return Ov000_EnterListScene;
}

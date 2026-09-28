/* Allocate and clear the 0xd18c scene context, configure the object at +0x68 with {10, 3}, and
 * initialise the interpolator sub-object at +0xd118. 0xd18c is measured off the MI_CpuFill8, not
 * inferred from the fields this function happens to touch. */

#include "nitro/types.h"

typedef struct {
    u16 width;
    u16 height;
} OverlayInitSize;

typedef struct {
    u8 pad_0000[0x68];
    u8 primary_object[0xd0b0];
    u8 secondary_object[0x74];
} OverlayContext;

extern OverlayContext *data_ov000_0205ac3c;
extern OverlayContext *NNSi_FndGetCurrentRootHeap(void);
extern void MI_CpuFill8(void *dst, int value, u32 size);
extern void Header_InitWithLimits(void *object, const OverlayInitSize *size);
extern void Tween_Clear(void *object);

void Ov000_CreateSceneContext(void) {
    OverlayInitSize size;
    OverlayContext *context = NNSi_FndGetCurrentRootHeap();

    MI_CpuFill8(context, 0, sizeof(OverlayContext));
    data_ov000_0205ac3c = context;
    size.width = 10;
    size.height = 3;
    Header_InitWithLimits(context->primary_object, &size);
    Tween_Clear(context->secondary_object);
}

/* Advance a 17-step fade; on completion publish the context, create the resource at +0x5074 and
 * return Ov000_FinishMoviePlayback (Ov000_FinishMoviePlayback) as the next callback. SEVENTEEN
 * steps is 0..16 inclusive -- the same ramp the other fades in this overlay produce as -(elapsed /
 * 0x4cb5), which is independent corroboration that 16 is the range and not a coincidence. */

typedef unsigned char u8;
typedef int (*OverlayCallback)(void);

typedef struct {
    int fade_counter;
    u8 pad_0004[8];
    u8 update_object[0x5068];
    void *resource;
} OverlayContext;

extern OverlayContext *NNSi_FndGetCurrentRootHeap(void);
extern OverlayContext *data_ov000_0205ac20;
extern u8 data_ov000_0205ab94[];
extern void Scene_DrawNode(void *object);
extern void SetMasterBrightnessMain(int value);
extern void SetMasterBrightnessSub(int value);
extern void Ov000_TeardownTitleScene(void);
extern void *InstantiateClass(const void *descriptor, int argument);
extern int Ov000_FinishMoviePlayback(void);

OverlayCallback Ov000_TickFadeThenPublishContext(void) {
    OverlayContext *context = NNSi_FndGetCurrentRootHeap();

    Scene_DrawNode(context->update_object);
    if (context->fade_counter <= 16) {
        SetMasterBrightnessMain(-context->fade_counter);
        SetMasterBrightnessSub(-context->fade_counter);
    } else {
        Ov000_TeardownTitleScene();
        data_ov000_0205ac20 = context;
        SetMasterBrightnessMain(-16);
        SetMasterBrightnessSub(-16);
        context->resource = InstantiateClass(data_ov000_0205ab94, 0);
        context->fade_counter = 0;
        return Ov000_FinishMoviePlayback;
    }

    context->fade_counter++;
    return 0;
}

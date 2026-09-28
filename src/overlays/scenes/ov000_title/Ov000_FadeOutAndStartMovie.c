/* Ov000_FadeOutAndStartMovie -- title scene: fade out, then start the movie player.
 *
 * heap[0] is a frame counter.  For the first 0x11 frames it drives the master brightness of
 * both screens down (-frame), then, once SoundStrm_HasPlaybackPos reports the fade is settled, it runs
 * the title teardown (Ov000_TeardownTitleScene), publishes the scene block in data_ov000_0205ac20,
 * loads ov012 and instantiates the movie-player class, parking the object at heap+0x5078.
 * Control then moves to Ov000_FinishMoviePlayback_2, which waits for the movie to end.  Until either
 * of those happens it bumps the counter and reports 0 (stay).
 *
 * The overlay id is the ADDRESS of a linker-absolute symbol (NitroSDK FS_OVERLAY_ID); dsd
 * emits `OVERLAY_12_ID = 12;` into arm9.lcf.  Spelled as a plain 12 the pool word disappears
 * and the function is 4 bytes short.
 */

#include "nitro/types.h"

typedef u32 FSOverlayID;
typedef void *StateFn;

extern u32 OVERLAY_12_ID[1];
#define FS_OVERLAY_ID_ov012 ((FSOverlayID)(u32) & (OVERLAY_12_ID))

extern void *NNSi_FndGetCurrentRootHeap(void);
extern void Scene_DrawNode(void *p);
extern void SetMasterBrightnessMain(int brightness);
extern void SetMasterBrightnessSub(int brightness);
extern int  SoundStrm_HasPlaybackPos(int arg);
extern void Ov000_TeardownTitleScene(void);
extern void LoadOverlaySync(int target, FSOverlayID id);
extern void *InstantiateClass(void *classDesc, int arg);
extern void *data_ov000_0205ac20;
extern int  data_ov012_0205c2bc;
extern void Ov000_FinishMoviePlayback_2(void);

StateFn Ov000_FadeOutAndStartMovie(void) {
    int *heap = (int *)NNSi_FndGetCurrentRootHeap();

    Scene_DrawNode((char *)heap + 0xc);
    if (heap[0] <= 0x10) {
        SetMasterBrightnessMain(-heap[0]);
        SetMasterBrightnessSub(-heap[0]);
    } else if (SoundStrm_HasPlaybackPos(0) == 0) {
        Ov000_TeardownTitleScene();
        data_ov000_0205ac20 = heap;
        LoadOverlaySync(0, FS_OVERLAY_ID_ov012);
        *(void **)((char *)heap + 0x5078) = InstantiateClass((void *)&data_ov012_0205c2bc, 1);
        return (StateFn)Ov000_FinishMoviePlayback_2;
    }
    heap[0] = heap[0] + 1;
    return 0;
}

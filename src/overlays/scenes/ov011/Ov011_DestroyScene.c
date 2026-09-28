/* Ov011_DestroyScene -- Ov011 scene teardown (the +8 class handler). Unloads the
 * ov024 (MobiClip) overlay. If scene-flags bit0 (threadAvail) is clear -- i.e. the
 * title path ran and actually allocated its resources -- it releases everything:
 * the message resource, two display objects, four list-node sub-buffers, two more
 * fields and five default-heap blocks. When no argument was passed (nArg == 0) it
 * dispatches two handlers and requests scene 9 via Scene_RequestPending(9, 0). Finally it
 * nulls globals->pScene. The overlay id must be taken as &OVERLAY_24_ID (an absolute
 * symbol) so it goes through the literal pool, matching the constructor.
 */

#include "nitro/types.h"

typedef u32 FSOverlayID;

extern u32 OVERLAY_24_ID[1];
#define FS_OVERLAY_ID_ov024 ((FSOverlayID)(u32) & (OVERLAY_24_ID))

typedef struct Ov011SceneFlags {
    int bThreadAvail : 1;
    int reserved     : 31;
} Ov011SceneFlags;

typedef struct Ov011Scene {
    u8    pad_0000[0xc];
    void *pMsgResource;
    void *heap10;
    void *heap14;
    u8    pad_0018[0x24 - 0x18];
    int   list24;
    u8    pad_0028[0x60 - 0x28];
    int   list60;
    u8    pad_0064[0x10954 - 0x64];
    void *heap10954;
    u8    pad_10958[0x10964 - 0x10958];
    int   list10964;
    u8    pad_10968[0x109a0 - 0x10968];
    int   list109a0;
    u8    pad_109a4[0x23a94 - 0x109a4];
    int   field23a94;
    u8    pad_23a98[0x23aa0 - 0x23a98];
    int   field23aa0;
    u8    pad_23aa4[0x23ac0 - 0x23aa4];
    Ov011SceneFlags flags;
    int   nArg;
    u8    pad_23ac8[0x23ad0 - 0x23ac8];
    int   obj23ad0;
    u8    pad_23ad4[0x28508 - 0x23ad4];
    int   obj28508;
    u8    pad_2850c[0x2cf44 - 0x2850c];
    void *heap2cf44;
    void *heap2cf48;
    u8    pad_2cf4c[0x2cf84 - 0x2cf4c];
} Ov011Scene;

typedef struct Ov011Globals {
    int         nCursor;
    Ov011Scene *pScene;
} Ov011Globals;

extern Ov011Globals data_ov011_0205e960;

extern void UnloadOverlaySync(int target, FSOverlayID id);
extern void ZeroHalfThenFree(void *resource);
extern void Obj_Release(void *obj);
extern void FreeAllListNodeSubBuffers(void *list);
extern void FreeFieldAt8(void *field);
extern void NNSi_FndFreeFromDefaultHeap(void *ptr);
extern void GameState_SetField(int id, int kind, int flag);
extern void Scene_RequestPending(int scene, int arg);

void Ov011_DestroyScene(void)
{
    UnloadOverlaySync(0, FS_OVERLAY_ID_ov024);
    if (data_ov011_0205e960.pScene->flags.bThreadAvail == 0) {
        ZeroHalfThenFree(data_ov011_0205e960.pScene->pMsgResource);
        Obj_Release(&data_ov011_0205e960.pScene->obj23ad0);
        Obj_Release(&data_ov011_0205e960.pScene->obj28508);
        FreeAllListNodeSubBuffers(&data_ov011_0205e960.pScene->list24);
        FreeAllListNodeSubBuffers(&data_ov011_0205e960.pScene->list60);
        FreeAllListNodeSubBuffers(&data_ov011_0205e960.pScene->list10964);
        FreeAllListNodeSubBuffers(&data_ov011_0205e960.pScene->list109a0);
        FreeFieldAt8(&data_ov011_0205e960.pScene->field23a94);
        FreeFieldAt8(&data_ov011_0205e960.pScene->field23aa0);
        NNSi_FndFreeFromDefaultHeap(data_ov011_0205e960.pScene->heap2cf48);
        NNSi_FndFreeFromDefaultHeap(data_ov011_0205e960.pScene->heap2cf44);
        NNSi_FndFreeFromDefaultHeap(data_ov011_0205e960.pScene->heap10);
        NNSi_FndFreeFromDefaultHeap(data_ov011_0205e960.pScene->heap14);
        NNSi_FndFreeFromDefaultHeap(data_ov011_0205e960.pScene->heap10954);
    }
    if (data_ov011_0205e960.pScene->nArg == 0) {
        GameState_SetField(0x44e, 3, 6);
        GameState_SetField(0, 9, 0x165);
        Scene_RequestPending(9, 0);
    }
    data_ov011_0205e960.pScene = 0;
}

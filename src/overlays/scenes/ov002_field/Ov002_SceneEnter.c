
#include "nitro/types.h"

typedef struct {
    char pad00[4];
    char *pContext;                 /* +0x04 */
} Ov002SceneRef;

extern Ov002SceneRef data_ov002_0207fa20;
extern int data_ov002_0207f468[];

extern char *NNSi_FndGetCurrentRootHeap(void);
extern void MI_CpuFill8(void *pDst, u8 nValue, unsigned int nSize);
extern void StoreGlobalPtrArray4At0c(int nKind, void *pHandler);
extern void Ov002_List_ClearTable(void);
extern int Msg_OpenContainerAndReadHeader(void *pTable, int nCount);
extern void Ov002_SetRootWord8a28(int nKind, int nHandle);
extern void Ov002_RouteSceneCommand(void);      /* the scene command router */
extern void Ov002_SceneStep(void);      /* the step this scene runs next */

/* Bring the session menu's scene up.
 *
 * The root heap block is the scene context.  The node lists the command router
 * indexes from +0x17c are cleared, the four words at +0x6c are zeroed and the
 * scale at +0x64 is set to one.  The router is handed to the kind 5
 * registration, and the command table produces the handle kept at +0x60, which
 * is passed straight on.  The current panel id is set to -1, meaning none,
 * which is what the panel overlay swap reads before deciding what to unload.
 *
 * Returns the step the scene runs next.
 */
void *Ov002_SceneEnter(void)
{
    char *pCtx;
    int i;
    char *pRow;

    pCtx = NNSi_FndGetCurrentRootHeap();
    data_ov002_0207fa20.pContext = pCtx;

    MI_CpuFill8(pCtx + 0x17c, 0, 0x80);
    StoreGlobalPtrArray4At0c(5, Ov002_RouteSceneCommand);

    i = 0;
    *(int *)(pCtx + 0x64) = 0x1000;
    pRow = pCtx;
    for (i = 0; i < 4; i++) {
        *(int *)(pRow + 0x6c) = 0;
        pRow += 4;
    }

    Ov002_List_ClearTable();
    *(u8 *)(pCtx + 0x68) = 0;

    *(int *)(pCtx + 0x60) = Msg_OpenContainerAndReadHeader(data_ov002_0207f468, 3);
    Ov002_SetRootWord8a28(1, *(int *)(pCtx + 0x60));

    *(signed char *)(data_ov002_0207fa20.pContext + 0x260) = -1;
    MI_CpuFill8(pCtx + 0x200, 0, 0x60);

    return (void *)Ov002_SceneStep;
}

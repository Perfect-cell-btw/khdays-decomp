/* Ov023_SceneEnter -- Ov023_SceneEnter: entry state of the event scene (ov023).  Takes the
 * current scene context (NNSi_FndGetCurrentRootHeap, kept in data_ov023_0208a780), touches
 * the slot table (020315f4), sets the status halfword to 1, builds the class arguments -- a
 * copy of the request (strcpy) followed by the request's byte at +0x7f -- and creates
 * the scene's main object (InstantiateClass on the class descriptor data_ov023_0208a038), kept at
 * context +4.  Moves on to the first-frame gate Ov023_SceneFirstFrame (02082a44). */
typedef unsigned short u16;

typedef struct Ov023SceneContext {
    u16  nStatus;             /* 0x00 */
    u16  pad_02;
    void *pMain;              /* 0x04 */
} Ov023SceneContext;

typedef struct Ov023SceneRequest {
    char szName[0x7f];        /* 0x00 */
    char nKind;               /* 0x7f */
} Ov023SceneRequest;

typedef struct Ov023MainArgs {
    char request[0x44];       /* 0x00 */
    int  nKind;               /* 0x44 */
} Ov023MainArgs;

extern Ov023SceneContext *NNSi_FndGetCurrentRootHeap(void);
extern void  Session_GetSlotTable(void);                /* Session_GetSlotTable */
extern void  strcpy(void *pDst, const void *pSrc);            /* copy a request record */
extern void *InstantiateClass(void *pClass, void *pArgs);               /* InstantiateClass */
extern int   Ov023_FirstFrameGate(void);                              /* Ov023_SceneFirstFrame */
extern Ov023SceneContext *data_ov023_0208a780;
extern char  data_ov023_0208a038[];                                  /* the main object's class */

void *Ov023_SceneEnter(Ov023SceneRequest *pRequest)
{
    Ov023MainArgs args;
    Ov023SceneContext *pContext;

    pContext = NNSi_FndGetCurrentRootHeap();
    Session_GetSlotTable();
    data_ov023_0208a780 = pContext;
    pContext->nStatus = 1;
    strcpy(&args, pRequest);
    args.nKind = pRequest->nKind;
    pContext->pMain = InstantiateClass(data_ov023_0208a038, &args);
    return Ov023_FirstFrameGate;
}

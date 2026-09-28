/* Scene entry: publish a 0x14-byte context, build its two objects, and pick the
 * opening transition.
 *
 * NNSi_FndGetCurrentRootHeap is genuinely called TWICE and the first result is
 * discarded -- that is what the ROM does, not a transcription slip.
 *
 * The tail is a three-way choice, not two: with data_ov005_0205b85c.nOption64
 * set it always runs RequestQueue_SetOrPushKind3(0x14); otherwise Session_IsActive gets to veto,
 * and only if that returns 0 does SetSelectionIfChanged(0x1e) run. */
typedef struct {
    void *pObjectA;         /* +0x00 */
    void *pObjectB;         /* +0x04 */
    int nMode;              /* +0x08 */
    char pad0c[8];
} Ov005SceneContext;        /* 0x14, measured off the MI_CpuFill8 */

typedef struct {
    char pad00[0x5c];
    unsigned char bMode;    /* +0x5c */
    char pad5d[7];
    int nOption64;          /* +0x64 */
} Ov005Config;

extern void *NNSi_FndGetCurrentRootHeap(void);
extern void MI_CpuFill8(void *dst, unsigned char value, unsigned int size);
extern void Ov005_InitializeGraphics(void);
extern void MsgDb_LoadDb(int a, int b);
extern void Ov005_InitializeResultConfiguration(void);
extern void *InstantiateClass(const void *res, int a);
extern int RequestQueue_SetOrPushKind3(int a);
extern int Session_IsActive(void);
extern void SetSelectionIfChanged(int a);
extern void Ov005_UpdateMenuExitTransition(void);

extern Ov005SceneContext *data_ov005_0205b808;
extern Ov005Config data_ov005_0205b85c;
extern char data_ov005_0205b590[];
extern char data_ov005_0205b4f0[];

void *Ov005_EnterSceneWithMode(int mode) {
    NNSi_FndGetCurrentRootHeap();
    data_ov005_0205b808 = NNSi_FndGetCurrentRootHeap();
    MI_CpuFill8(data_ov005_0205b808, 0, 0x14);
    data_ov005_0205b808->nMode = mode;
    Ov005_InitializeGraphics();
    MsgDb_LoadDb(0x15, 0xe);
    MsgDb_LoadDb(0x1a, 0xe);
    MsgDb_LoadDb(0x19, 0xe);
    Ov005_InitializeResultConfiguration();
    data_ov005_0205b808->pObjectB = InstantiateClass(data_ov005_0205b590, 0);
    data_ov005_0205b808->pObjectA = InstantiateClass(data_ov005_0205b4f0, 0);
    if (data_ov005_0205b85c.nOption64 != 0) {
        RequestQueue_SetOrPushKind3(0x14);
    } else if (Session_IsActive() == 0) {
        SetSelectionIfChanged(0x1e);
    }
    return (void *)&Ov005_UpdateMenuExitTransition;
}

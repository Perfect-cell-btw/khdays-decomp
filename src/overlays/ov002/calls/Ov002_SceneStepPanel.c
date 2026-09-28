/*
 * Ov002_SceneStepPanel - the panel scene's per-frame step.
 *
 * Nothing runs while the owning system reports it has no slot. Otherwise the
 * camera is committed with the tight bounds the flat widgets are drawn in, the
 * counter half is stepped and drawn while it is in one of its three live
 * states, and the backdrop while it is in one of its two.
 *
 * The camera is then committed again with the wide bounds the world markers
 * need, the markers and the HUD are drawn, and the camera is committed one last
 * time from the actor itself.
 *
 * ARM.
 */

typedef struct {
    char pad000[4];
    char aCamera[0x38];
    char pad03c[0xa8];
    int nHeaderFrame;
    char pad0e8[0xc70];
    int nCounterState;
    char padd5c[0x290];
    int nBackdropState;
} Ov002PanelScene;

extern int data_ov002_0207f628;

extern int func_ov022_02083f0c(void);
extern void *Ov002_GetWord20(void);
extern void Camera_CommitMatricesEx(void *pCam, int a, int b, int c, int d);
extern void Camera_CommitMatrices(void *pCam);

extern void Ov002_SceneDrawPanelWidgets(void);
extern void Ov002_SceneStepPanelFlash(void);
extern void Ov002_SceneStepPanelRowFx(void);
extern void Ov002_SceneDrawPanelTotal(void);
extern void Ov002_SceneStepPanelCounters(void);
extern void Ov002_SceneStepPanelBlink(void);
extern void Ov002_SceneStepPanelBackdrop(void);
extern void Ov002_DrawMarkerQueue(void *pCam);
extern void Ov002_SceneStepPanelHud(void);
extern void Ov002_SweepParkedValues(void *pCam);
extern void Ov002_ResetFollowOffset(void);

void *Ov002_SceneStepPanel(void)
{
    Ov002PanelScene *s;
    void *pCam;

    s = *(Ov002PanelScene **)&data_ov002_0207f628;
    if (func_ov022_02083f0c() == -1) {
        return 0;
    }
    pCam = Ov002_GetWord20();
    Camera_CommitMatricesEx(s->aCamera, 0x3b33, -0x3b33, -0x4d9a, 0x4d9a);

    switch (s->nCounterState) {
    case 0:
    case 1:
    case 2:
        switch (s->nHeaderFrame) {
        case 0:
        case 1:
            Ov002_SceneDrawPanelWidgets();
            break;
        }
        Ov002_SceneStepPanelCounters();
        Ov002_SceneDrawPanelTotal();
        break;
    }
    switch (s->nBackdropState) {
    case 0:
    case 1:
        Ov002_SceneStepPanelBackdrop();
        break;
    }
    Ov002_SceneStepPanelFlash();
    Ov002_SceneStepPanelRowFx();
    Ov002_SceneStepPanelBlink();

    Camera_CommitMatricesEx(s->aCamera, 0x5f000, -0x5f000, -0x7f000, 0x7f000);
    Ov002_DrawMarkerQueue(pCam);
    Ov002_SceneStepPanelHud();
    Ov002_SweepParkedValues(pCam);
    Ov002_ResetFollowOffset();
    Camera_CommitMatrices(pCam);
    return 0;
}

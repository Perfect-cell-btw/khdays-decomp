extern void Ov002_ForwardToSubDc(int id);
extern void Ov002_Ctx_InvokeTagTrackerCallback(void);
extern void Ov002_AppendEntry(void *desc, void *handler, int arg);
extern void Ov002_RedrawCaptionTallies(void);
extern void Ov002_DrainSceneQueue(void);
extern void Ov002_TickOptionsPage(void);
extern void Ov002_OpenOptionPage(void);
extern void Ov002_LoadTaskPalette(void);
extern void Ov002_TakePageCharHeader(void);
extern void Ov002_CommitPageAndSubmit(void);
extern int data_ov002_0207ed88;
extern int data_ov002_0207eda4;
extern int data_ov002_0207edbc;
extern int data_ov002_0207edd8;

/* Builds the four buttons of this page and draws it for the first time. */
void Ov002_BuildOptionsPage(void) {
    Ov002_ForwardToSubDc(0x3e5);
    Ov002_Ctx_InvokeTagTrackerCallback();
    Ov002_AppendEntry(&data_ov002_0207ed88, (void *)&Ov002_OpenOptionPage, 0);
    Ov002_AppendEntry(&data_ov002_0207eda4, (void *)&Ov002_LoadTaskPalette, 0);
    Ov002_AppendEntry(&data_ov002_0207edbc, (void *)&Ov002_TakePageCharHeader, 0);
    Ov002_AppendEntry(&data_ov002_0207edd8, (void *)&Ov002_CommitPageAndSubmit, 0);
    Ov002_RedrawCaptionTallies();
    Ov002_DrainSceneQueue();
    Ov002_TickOptionsPage();
}

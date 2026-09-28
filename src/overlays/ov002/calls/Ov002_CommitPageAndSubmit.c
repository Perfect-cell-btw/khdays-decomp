/* Commit the page and hand its image to the graphics queue. With no context the
 * page is just released. Otherwise the page's block header is fetched, the image
 * is submitted through Ov002_EnqueueAndRecordCommand, and -- when nothing is pending and
 * the counter is positive -- the pending slots are cleared and any queued sound
 * stopped. The 0x412 tag-tracker refresh runs unless the global at
 * data_0204c240 has a non-zero value with bit 0 clear. */
extern int data_ov002_0207f634;
extern unsigned char data_0204c240;

extern void *Ov002_Field_GetBlock194(void);
extern void Ov002_DestroyOwnedEntry(void *page, int a);
extern int NNS_G2dGetUnpackedPaletteData(int block, void *out);
extern void Ov002_EnqueueAndRecordCommand(int a, int b, int c, int d, int e);
extern int *Ov002_GetMissionProgress(void);
extern int Ov002_GetPanelField0058(void);
extern void ForwardToHandlerOrCurrentObject(int a, int b, int c);
extern void Ov002_FlushPendingDraw(void);
extern int Ov002_GetRootField8d18(void);
extern int Ov002_ForwardToSubDc(int tag);
extern void Ov002_Ctx_InvokeTagTrackerCallback(int a);
extern void Ov002_PageSubmitHookNoOp(void);
extern void GFXi_EnqueueCommand(int cmd, int a, int b, int c);

void Ov002_CommitPageAndSubmit(int *page) {
    int *hdr;
    int *ctx = *(int **)&data_ov002_0207f634;
    int *pending = (int *)Ov002_Field_GetBlock194();
    int *counter;

    if (ctx == 0) {
        Ov002_DestroyOwnedEntry(page, 1);
        return;
    }

    NNS_G2dGetUnpackedPaletteData(page[2], &hdr);
    Ov002_EnqueueAndRecordCommand(0x1f, 0, hdr[3], hdr[2], page[2]);
    Ov002_DestroyOwnedEntry(page, 0);

    counter = Ov002_GetMissionProgress();
    if (Ov002_GetPanelField0058() == 0 && *counter > 0) {
        pending[4] = 0;
        pending[5] = 0;
        if (pending[2] != 0) {
            ForwardToHandlerOrCurrentObject(0, 0x32, 0);
            pending[2] = 0;
        }
        Ov002_FlushPendingDraw();
    }

    if (data_0204c240 == 0 || (data_0204c240 & 1) != 0) {
        if (Ov002_GetRootField8d18() > 0) {
            Ov002_Ctx_InvokeTagTrackerCallback(Ov002_ForwardToSubDc(0x412));
        }
    }

    Ov002_PageSubmitHookNoOp();
    GFXi_EnqueueCommand(0x16, 0x1a60, ctx[7], 0x40);
}

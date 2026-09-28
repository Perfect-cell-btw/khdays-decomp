/* Loads ov024 (MobiClip), installs its stream source interface into the root context and calls its
 * entry hook. */

typedef void (*Ov002OverlayHook)(void);
typedef unsigned int FSOverlayID;

extern unsigned int OVERLAY_24_ID[1];
#define FS_OVERLAY_ID_ov024 ((FSOverlayID)(unsigned int)&OVERLAY_24_ID)

typedef struct {
    unsigned char pad0000[0x8b50];
    int nOverlayId;
    unsigned char pad8b54[0x28];
    Ov002OverlayHook pOverlayHook;
} Ov002RootContext;

extern Ov002RootContext *data_ov002_0207fa00;
extern void LoadOverlaySync(int processor, int overlayId);
extern void Ov024_MobiClip_InstallStreamSourceVtbl(Ov002OverlayHook *hook);

void Ov002_EnterOverlay24(void)
{
    Ov002RootContext *root = data_ov002_0207fa00;

    root->nOverlayId = FS_OVERLAY_ID_ov024;
    LoadOverlaySync(0, root->nOverlayId);
    Ov024_MobiClip_InstallStreamSourceVtbl(&root->pOverlayHook);
    root->pOverlayHook();
}

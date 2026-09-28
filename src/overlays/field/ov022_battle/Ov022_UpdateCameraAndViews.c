/* Per-frame battle update: re-aims the camera at the local actor (the argument says whether to turn
 * it; skipped while paused), draws the local group's view lists and link seats, updates the peers'
 * animations and applies the scene scale to the views. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Ov022Context {
    u16 flags;
    char pad_0002[0x32];
    int scale;
} Ov022Context;

extern Ov022Context *data_ov022_020b2e60;
extern u8 data_0204be04;

extern int func_ov022_02083f0c(void);
extern u32 func_ov022_02088338(void);
extern int QueryActiveStateOrDelegate(void);
extern void Ov002_ReaimActor(int actor, int mode);
extern int Ov022_GetEntryField66(int index);
extern void Ov002_RenderLinkSeatEntries(void);
extern void Render_DrawViewLists(int index);
extern u32 func_ov022_0208848c(void);
extern void Ov002_UpdatePeerAnimationsAndExit(int worldId, int scale, int enabled);
extern void Ov002_FlushPendingObjectCommands(void);
extern int LoadGlobalU16At0(void);
extern void Render_ApplyFactorToViews(u32 mask, int scale);

void Ov022_UpdateCameraAndViews(int mode)
{
    int actor = func_ov022_02083f0c();
    u32 enabled = func_ov022_02088338();
    int index = QueryActiveStateOrDelegate();
    u32 mask;

    if ((data_ov022_020b2e60->flags & 8) == 0) {
        Ov002_ReaimActor(actor, mode);
    }

    index = Ov022_GetEntryField66(index);
    if (index >= 0) {
        Ov002_RenderLinkSeatEntries();
        Render_DrawViewLists((u16)index);
    }

    mask = func_ov022_0208848c();
    if (enabled == 0) {
        return;
    }

    if (index >= 0) {
        Ov022Context *context = data_ov022_020b2e60;
        Ov002_UpdatePeerAnimationsAndExit(
            index,
            context->scale,
            (context->flags & 0xbc) == 0);
        Ov002_FlushPendingObjectCommands();
    }

    if (LoadGlobalU16At0() == 0x2a) {
        mask = 1 << data_0204be04;
    }

    Render_ApplyFactorToViews(mask, data_ov022_020b2e60->scale);
}

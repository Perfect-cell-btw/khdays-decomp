/* Bring the mission overlays in and hand control to the scene hook.
 *
 * The overlay ids are the ADDRESSES of linker-absolute symbols, the NitroSDK FS_OVERLAY_ID idiom:
 * dsd emits `OVERLAY_22_ID = 22;` into arm9.lcf, so the id reaches the code as a literal-pool word
 * with no relocation. Written as plain 22 and 69 the pool words disappear and this compiler uses
 * immediates instead, which is how the idiom shows up in the bytes.
 *
 * ov022 is loaded unconditionally and its id is remembered in the root context; ov069 comes in as
 * well when the mode word reads 7, and its table is registered as entry 0x13. Finally the hook the
 * context holds is initialised and then called.
 */

typedef unsigned int u32;
typedef u32 FSOverlayID;

extern u32 OVERLAY_22_ID[1];
extern u32 OVERLAY_69_ID[1];
#define FS_OVERLAY_ID_ov022 ((FSOverlayID)(u32) & (OVERLAY_22_ID))
#define FS_OVERLAY_ID_ov069 ((FSOverlayID)(u32) & (OVERLAY_69_ID))

extern char *data_ov002_0207fa00;
extern char data_ov069_020baa84[];
extern void LoadOverlaySync(int processor, FSOverlayID id);
extern void StoreGlobalArrayEntry(int index, void *value);
extern void Ov022_FillSceneVTable(void *hook);

void Ov002_BringUpMissionOverlays(void) {
    char *ctx = data_ov002_0207fa00;

    *(FSOverlayID *)(ctx + 0x8b50) = FS_OVERLAY_ID_ov022;
    LoadOverlaySync(0, *(FSOverlayID *)(ctx + 0x8b50));
    if (*(int *)(ctx + 0x8b58) == 7) {
        LoadOverlaySync(0, FS_OVERLAY_ID_ov069);
        StoreGlobalArrayEntry(0x13, data_ov069_020baa84);
    }
    Ov022_FillSceneVTable(ctx + 0x8b7c);
    (*(void (**)(void))(ctx + 0x8b7c))();
}

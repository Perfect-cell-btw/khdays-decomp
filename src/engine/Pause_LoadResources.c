extern int Archive_LoadFile(void *path, int heap);
extern void Res_LoadSpriteSet(void *info, int arch, int a, int b, int c);
extern void *AllocAndRegisterOrFree(int slot, int path, int heap);

extern int data_0204be08[];
extern char gPausePausebgPath[];
extern char gPausePauseiconPath[];
extern char gPausePausemsgPath[];
extern char gPauseEtciconPath[];

/* Load the pause menu's resources into the global UI context.  The four paths are
 *   gPausePausebgPath "pause/pausebg_&.pbg.z"   gPausePauseiconPath "pause/pauseicon.NSCR.z"
 *   gPausePausemsgPath "pause/pausemsg.NSCR.z"   gPauseEtciconPath "pause/etcicon.NSCR.z"
 * The background is loaded and its cells built; the three NSCR screens are each
 * allocated-and-registered into their own slot.
 *
 * ctx+0x9c is deliberately re-read for the Res_LoadSpriteSet call instead of reusing
 * the value just stored -- caching it in a local costs the reload the ROM does. */
void Pause_LoadResources(void) {
    char *ctx = (char *)data_0204be08[1];

    *(int *)(ctx + 0x9c) = Archive_LoadFile(gPausePausebgPath, 0xf);
    Res_LoadSpriteSet(ctx + 0xa0, *(int *)(ctx + 0x9c), 0, 0, 0);
    *(int *)(ctx + 0x10) = (int)AllocAndRegisterOrFree((int)(ctx + 0x1c), (int)gPausePauseiconPath, 0xf);
    *(int *)(ctx + 0x14) = (int)AllocAndRegisterOrFree((int)(ctx + 0x20), (int)gPausePausemsgPath, 0xf);
    *(int *)(ctx + 0xc) = (int)AllocAndRegisterOrFree((int)(ctx + 0x18), (int)gPauseEtciconPath, 0xf);
}

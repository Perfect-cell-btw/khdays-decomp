/* * Two things were wrong, and the old header blamed the compiler for both:
 * "the ROM fuses the sub/scene null checks into conditional loads + a conditional early-return
 * (ldreq/cmpeq/popeq / ldrne/cmpne/beq) that a structural transcription over-expands (+24B)."
 *  - Ov008_SelectMenuGroupAndDrawCaption takes TWO args, not four (the ROM sets only r0/r1).
 *  - the guards are just two plain `&&` chains. The old C juggled a `scene` variable through
 *    three separate ifs to "transcribe the structure"; writing the conditions the obvious way
 *    (`sub == 0 && rec->0x90 == 0` / `sub != 0 && rec->0x90 != 0`) produces the ROM's conditional
 *    loads and early-return by itself. mwcc if-converts short-circuit chains on its own -- it does
 *    not need help, and helping it is what cost the 24 bytes.
 * This function also takes NO parameters; it had four. (2026-07-17)
 */
/* Ov008_ConfirmMenuItem -- confirm the highlighted main-menu item, ov008.
 * Looks up the active menu record (Ov008_GetMenuContext); its two targets are a sub-menu
 * (rec+0x8c) and a scene (rec+0x90). When only the scene target is set, tears the menu down
 * (02050e2c/020511c8/02050fe0/02051010) and either fires the transition (when story flag 0x35bd
 * is clear: prime 0x1e-frame fade, post the event, request state 4) or replays it
 * (Ov008_SetTargetSlot(1,-1)). When a sub-menu target is set, descends into it
 * (Ov008_SelectMenuGroupAndDrawCaption). Either way commits the input latch (PlaySound(0,1)). */
extern int  Ov008_GetMenuContext(void);
extern void Ov008_SelectMenuGroupAndDrawCaption(int rec, int a);
extern void Ov008_SetCtxField9678(int a);
extern void Ov008_SetCtxField967c(int a);
extern void Ov008_SetCtxObject9630(int a);
extern void Ov008_SetCtxObject9634(int a);
extern int  GameState_IsFlagSet(int flag);
extern void Ov008_ArmCueRequest(int a, int b, int c);
extern void GameState_SetFlag(int flag);
extern void Ov008_SetGlobalConfigAndInit(int a);
extern void Ov008_SetTargetSlot(int a, int b);
extern void PlaySound(int a, int b);

void Ov008_ConfirmMenuItem(void) {
    int rec = Ov008_GetMenuContext();
    int sub = *(int *)(rec + 0x8c);

    if (sub == 0 && *(int *)(rec + 0x90) == 0) {
        return;
    }
    if (sub != 0 && *(int *)(rec + 0x90) != 0) {
        Ov008_SelectMenuGroupAndDrawCaption(rec, 1);
    } else {
        Ov008_SetCtxField9678(0);
        Ov008_SetCtxField967c(0);
        Ov008_SetCtxObject9630(1);
        Ov008_SetCtxObject9634(*(int *)(rec + 0x90));
        if (GameState_IsFlagSet(0x35bd) == 0) {
            Ov008_ArmCueRequest(0x1e, 1, 1);
            GameState_SetFlag(0x35bd);
            Ov008_SetGlobalConfigAndInit(4);
        } else {
            Ov008_SetTargetSlot(1, -1);
        }
    }
    PlaySound(0, 1);
}

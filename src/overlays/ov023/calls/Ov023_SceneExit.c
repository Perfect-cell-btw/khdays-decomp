/* Ov023_SceneExit -- ov023 scene exit. Kind 0x10 is the quiet path: run the teardown and
 * report 0. Anything else reports 1, and additionally fires the 0xe cue when the global mode
 * (LoadGlobalU16At0) is 4. */
extern void Ov023_Teardown(void);
extern void StoreToGlobalPtr4FieldE4IfSet(int a);
extern int LoadGlobalU16At0(void);
extern void GX_SetGraphicsMode(int a, int b, int c);

void Ov023_SceneExit(int kind) {
    if (kind == 0x10) {
        Ov023_Teardown();
        StoreToGlobalPtr4FieldE4IfSet(0);
        return;
    }
    if (LoadGlobalU16At0() == 4) {
        GX_SetGraphicsMode(0xe, 4, 1);
    }
    StoreToGlobalPtr4FieldE4IfSet(1);
}

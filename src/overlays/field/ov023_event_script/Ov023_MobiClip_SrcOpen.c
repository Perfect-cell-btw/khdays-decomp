/* Ov023_MobiClip_SrcOpen -- open a source and park the handle in a single global.
 * Opens through InstantiateClass with the descriptor at data_ov023_0208a004 and the caller's
 * argument, storing the handle in data_ov023_0208a000 -- one live source at a time, not
 * per-instance state.
 *
 * PROVENANCE: byte-identical twin of Ov024_MobiClip_SrcOpen -- same code, this overlay's own
 * globals, propagated mechanically and verified byte-exact.
 * ov023 is NOT MobiClip -- it is a separate subsystem (221 funcs, heavy ScriptVm_ReadOperandInt /
 * OS_SPrintf use). Only the code SHAPE is shared with the rep; the MobiClip framing that
 * came with the twin source has been removed rather than guessed at.
 */
extern int InstantiateClass(void *desc, int arg);
extern int data_ov023_0208a004;
extern int data_ov023_0208a000;

void Ov023_MobiClip_SrcOpen(int arg) {
    data_ov023_0208a000 = InstantiateClass(&data_ov023_0208a004, arg);
}

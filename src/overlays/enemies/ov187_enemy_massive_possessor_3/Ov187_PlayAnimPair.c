/* Ov187_PlayAnimPair -- head of a 5-member family (228 B). Re-arm the object's two sub-item
 * slots (0 and 3): in mode 3 rebuild each one from Obj_GetCellScaledField's fresh handle, otherwise set
 * both directly to `mode`. Then, if the object has a parent (+0x390) and its kind byte (+0x1c6)
 * is not 7, run the ov117 refresh, and finally re-register the object.
 *
 * Read off the disassembly (all wrong in Ghidra): Obj_GetCellScaledField takes 3, callIfTableEntrySet takes 3,
 * AnimObj_BindTrackAtLastFrame takes 4, SetSubitemState takes 4, RefreshObjectCallbacks takes 2.
 *
 * The single instruction that kept this parked (`mov r6, r1` at the top, i.e. 4 bytes short) was
 * NOT "mwcc has no reason to save mode". It is the SIGN EXTENSION: written as `(short)mode` at
 * both call sites, mwcc common-subexpressions the cast into one callee-saved register and never
 * needs `mode` itself afterwards; the ROM keeps the full int in r6 and re-does `lsl #16 / asr #16`
 * at each site. Declaring the callee's third parameter `short` and passing plain `mode` puts the
 * conversion in the argument-passing sequence instead of in an expression, so it is emitted twice
 * and `mode` stays live across the first call. A cast you write twice can still be CSEd; a
 * PROTOTYPE conversion cannot. */
extern int  Obj_GetCellScaledField();
extern void callIfTableEntrySet();
extern void AnimObj_BindTrackAtLastFrame();
extern void SetSubitemState(int a, int b, short c, int d);
extern void Ov187_UnlinkHeldNode(int self);
extern void RefreshObjectCallbacks(int a, int b);

void Ov187_PlayAnimPair(int self, int mode, int arg) {
    if (mode == 3) {
        callIfTableEntrySet(*(int *)(self + 0x384), 0, Obj_GetCellScaledField(*(int *)(self + 0x384), 0, 0));
        AnimObj_BindTrackAtLastFrame(*(int *)(self + 0x384), 0, 0, arg);
        callIfTableEntrySet(*(int *)(self + 0x384), 3, Obj_GetCellScaledField(*(int *)(self + 0x384), 3, 0));
        AnimObj_BindTrackAtLastFrame(*(int *)(self + 0x384), 3, 0, arg);
    } else {
        SetSubitemState(*(int *)(self + 0x384), 0, mode, arg);
        SetSubitemState(*(int *)(self + 0x384), 3, mode, arg);
    }
    if (*(int *)(self + 0x390) != 0 && *(signed char *)(self + 0x1c6) != 7) {
        Ov187_UnlinkHeldNode(self);
    }
    RefreshObjectCallbacks(*(int *)(self + 0x384), 0);
}

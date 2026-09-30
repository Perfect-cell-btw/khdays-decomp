/* Ov187_RetuneRigKindSlots03 -- x3. Retune the rig at +0x384 for a kind selector, then reset it.
 * For kind 3 the two rig slots 0 and 3 are each reprogrammed in full: seed slot i with
 * be9c(rig, i, be68(rig, i, 0)) then arm it with babc(rig, i, 0, arg). Any other kind just retunes
 * both slots with the kind as a signed 16-bit selector via b9fc(rig, {0,3}, (short)kind, arg).
 * Always finishes with a reset (0203c7ac). */
extern int  Obj_GetCellScaledField(int rig, int idx, int idx2);
extern void callIfTableEntrySet(int rig, int idx, int val);
extern void AnimObj_BindTrackAtLastFrame(int rig, int idx, int c, int arg);
extern void SetSubitemState(int rig, int a, short kind, int arg);
extern void RefreshObjectCallbacks(int rig, int a);

void Ov187_RetuneRigKindSlots03(int self, int kind, int arg) {
    if (kind == 3) {
        callIfTableEntrySet(*(int *)(self + 0x384), 0, Obj_GetCellScaledField(*(int *)(self + 0x384), 0, 0));
        AnimObj_BindTrackAtLastFrame(*(int *)(self + 0x384), 0, 0, arg);
        callIfTableEntrySet(*(int *)(self + 0x384), 3, Obj_GetCellScaledField(*(int *)(self + 0x384), 3, 0));
        AnimObj_BindTrackAtLastFrame(*(int *)(self + 0x384), 3, 0, arg);
    } else {
        SetSubitemState(*(int *)(self + 0x384), 0, (short)kind, arg);
        SetSubitemState(*(int *)(self + 0x384), 3, (short)kind, arg);
    }
    RefreshObjectCallbacks(*(int *)(self + 0x384), 0);
}

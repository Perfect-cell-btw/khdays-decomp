/* Ov024_MobiClip_OpenDescPair -- MobiClip: resolve two descriptor entries and open the pair (THUMB).
 * Entries are 8 bytes apart, same layout Ov024_MobiClip_ResolveStreamDescs walks. Both handles go to
 * Ov024_MobiClip_BeginScreenFade together; the constant 6 is the resulting stream state.
 * blx because 02082e04 is ARM. */
extern int ScriptVm_ReadOperandInt(int owner, char *entry);
extern void Ov024_MobiClip_BeginScreenFade(int a, int b);

int Ov024_MobiClip_OpenDescPair(int owner, char *desc) {
    int a;
    int b;

    a = ScriptVm_ReadOperandInt(owner, desc);
    b = ScriptVm_ReadOperandInt(owner, desc + 8);
    Ov024_MobiClip_BeginScreenFade(a, b);
    return 6;
}

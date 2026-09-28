/* Ov024_MobiClip_DecoderInitTrampoline -- MobiClip: decoder-init trampoline. Runs the pre-init hook
 * against the static object at 0x02000ba4 before handing over to the real init. Returns whether the
 * container opened. */
extern void OSi_ReferSymbol(void *p);
extern int Ov024_MobiClip_OpenContainer(int *ctx, int cursor, unsigned int a);

int Ov024_MobiClip_DecoderInitTrampoline(int *ctx, int cursor, unsigned int a) {
    OSi_ReferSymbol((void *)0x02000ba4);
    return Ov024_MobiClip_OpenContainer(ctx, cursor, a);
}

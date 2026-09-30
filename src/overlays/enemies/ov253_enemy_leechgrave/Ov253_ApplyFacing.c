/* Ov253_ApplyFacing -- point the object at the angle its facing byte (+0x450) names: the byte is
 * scaled by 0x6488 (a quarter turn per unit / 4) and applied to the transform at +0xa0, then the
 * hit box at +0x3a8 and the base handler are told about the change.
 * The `/ 4` is a SIGNED divide -- that is the ROM's `asr #1 ; add lsr #30 ; asr #2` triple, not a
 * shift. */
extern void Srt_SetRotationAxisAngle(int dst, void *src, int v);
extern void Sequence_UpdateTracks(int a, int b);
extern void Ov107_ProcessObjectTick(int obj, int arg);
extern int data_02042264;

void Ov253_ApplyFacing(int obj, int arg) {
    Srt_SetRotationAxisAngle(obj + 0xa0, &data_02042264,
                  *(signed char *)(obj + 0x450) * 0x6488 / 4);
    Sequence_UpdateTracks(*(int *)(*(int *)(obj + 0x3a8) + 0x88), arg);
    Ov107_ProcessObjectTick(obj, arg);
}

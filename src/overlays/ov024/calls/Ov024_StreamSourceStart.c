/* Ov024_StreamSourceStart -- play SFX 0x14 and raise the ov024 refresh flag, ov024
 * (*(&data_ov024_02093a20+4) -> u16 = 1). */
extern void RequestQueue_SetOrPushKind3(int soundId);
extern int data_ov024_02093a20;
void Ov024_StreamSourceStart(void) {
    RequestQueue_SetOrPushKind3(0x14);
    *(unsigned short *)(*(char **)((char *)&data_ov024_02093a20 + 4)) = 1;
}

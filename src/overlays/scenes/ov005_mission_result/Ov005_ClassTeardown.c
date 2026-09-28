/* Ov005_ClassTeardown -- play SFX 0x13 and reset the ov005 blink timer, ov005. */
extern void ClearGlobalArrayInt(int soundId);
extern int data_ov005_0205b8d0;
void Ov005_ClassTeardown(void) {
    ClearGlobalArrayInt(0x13);
    data_ov005_0205b8d0 = 0;
}

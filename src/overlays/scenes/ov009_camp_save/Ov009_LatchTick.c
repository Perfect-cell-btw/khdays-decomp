#pragma thumb on
/* Ov009_LatchTick -- snapshot the current tick into data_0204be1c, ov009 (byte-identical twin of an ov000 helper). */
extern unsigned long long OS_GetTick(void);
extern unsigned long long data_0204be1c;
void Ov009_LatchTick(void) {
    data_0204be1c = OS_GetTick();
}

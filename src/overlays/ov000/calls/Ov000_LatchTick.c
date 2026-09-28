#pragma thumb on
/* Ov000_LatchTick -- snapshot the current tick into data_0204be1c, ov000. */
extern unsigned long long OS_GetTick(void);
extern unsigned long long data_0204be1c;
void Ov000_LatchTick(void) {
    data_0204be1c = OS_GetTick();
}

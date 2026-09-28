/* Records the current OS tick in a global. */

extern long long OS_GetTick();
extern int data_0204be1c;

void Ov025_LatchTick(void) {
    *(long long *)&data_0204be1c = OS_GetTick();
}

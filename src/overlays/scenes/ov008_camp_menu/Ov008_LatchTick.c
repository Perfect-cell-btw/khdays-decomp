/* Records the current OS tick in a global. */

extern long long OS_GetTick(void);
extern long long data_0204be1c;
void Ov008_LatchTick(void)
{
    data_0204be1c = OS_GetTick();
}

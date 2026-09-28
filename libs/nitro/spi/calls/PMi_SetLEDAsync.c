/* NitroSDK spi (pm.c): PMi_SetLEDAsync -- maps the LED status to a PM utility command and sends it
 * through PM_SendUtilityCommandAsync (callback/arg pass through in r1/r2); 0xffff = PM_INVALID_COMMAND. */
extern int PM_SendUtilityCommandAsync(int arg);

int PMi_SetLEDAsync(int arg0)
{
    int v;
    switch (arg0) {
    case 1: v = 1; break;
    case 3: v = 2; break;
    case 2: v = 3; break;
    default: v = 0; break;
    }
    if (v == 0) return 0xffff;
    return PM_SendUtilityCommandAsync(v);
}

/* Tail-call Ov105_WMi_StartParentEx with flag 1. */
extern int Ov105_WMi_StartParentEx(int a, int b);
int Ov105_ResourceEntryCallback(int param_1) {
    return Ov105_WMi_StartParentEx(param_1, 1);
}

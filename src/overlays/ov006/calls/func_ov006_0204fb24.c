/* func_ov006_0204fb24 -- release the Mission Mode's secondary resource handle, ov006.
 * Frees the resource object stored in the roster table slot [1] (data_ov006_020565e4[1]) via
 * func_02023ad0 and clears the slot. No-op if the slot is empty. */
extern void func_02023ad0(int p);
extern int  data_ov006_020565e4[];

void func_ov006_0204fb24(void) {
    if (data_ov006_020565e4[1] == 0) {
        return;
    }
    func_02023ad0(data_ov006_020565e4[1]);
    data_ov006_020565e4[1] = 0;
}

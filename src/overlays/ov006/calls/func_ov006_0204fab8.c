/* func_ov006_0204fab8 -- sample the RTC-availability flag and forward it, ov006. */
extern int func_01ff8138(void);
extern void func_ov006_0204feb0(short *p);
void func_ov006_0204fab8(void) {
    short avail = func_01ff8138();
    func_ov006_0204feb0(&avail);
}

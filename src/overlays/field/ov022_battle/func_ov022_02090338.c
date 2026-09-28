extern int Session_IsReady(void);
void func_ov022_02090338(unsigned short *arg0) {
    if (Session_IsReady()) {
        if ((*arg0 & 0x100) != 0) *arg0 &= ~0x100;
    }
}

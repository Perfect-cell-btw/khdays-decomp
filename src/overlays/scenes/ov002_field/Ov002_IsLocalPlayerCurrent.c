/* True when the link context's stored player index (+0xa) is the running one. */

extern int data_ov002_0207fa04;
extern unsigned short GetGlobalU16At6(void);

int Ov002_IsLocalPlayerCurrent(void) {
    int ctx = *(int *)&data_ov002_0207fa04;
    return *(unsigned char *)(ctx + 0xa) == GetGlobalU16At6();
}

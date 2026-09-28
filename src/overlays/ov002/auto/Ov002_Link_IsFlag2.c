/* Whether link flag bit 1 is set. */

extern int data_ov002_0207fa08;

int Ov002_Link_IsFlag2(void) {
    return (*(int *)*(int *)&data_ov002_0207fa08 & 2) > 0;
}

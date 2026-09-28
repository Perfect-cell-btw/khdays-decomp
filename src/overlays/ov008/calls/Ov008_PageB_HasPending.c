/* Whether page B is active and has a pending action. */

extern void *Ov008_GetPageB(void);
extern int data_ov008_02090f20[];

int Ov008_PageB_HasPending(void)
{
    void *context = Ov008_GetPageB();
    int result = 0;

    if (data_ov008_02090f20[0] == 0) {
        return result;
    }

    if (*(int *)context != 0 || *(int *)((char *)context + 0x14) != 0) {
        result = 1;
    }

    return result;
}

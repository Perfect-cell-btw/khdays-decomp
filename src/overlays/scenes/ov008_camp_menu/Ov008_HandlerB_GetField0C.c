/* Follow the +0xc link of the stride-8 table entry indexed by the second ov008 counter. */

struct ov008_ptr_slot {
    char *ptr;
    int _pad;
};

extern int data_ov008_02090f0c[];
extern struct ov008_ptr_slot data_ov008_02090064[];
int Ov008_HandlerB_GetField0C(void)
{
    return *(int *)(data_ov008_02090064[data_ov008_02090f0c[1]].ptr + 0xc);
}

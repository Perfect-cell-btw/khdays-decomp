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

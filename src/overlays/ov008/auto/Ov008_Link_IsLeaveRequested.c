extern char *data_ov008_02090f24;
int Ov008_Link_IsLeaveRequested(void)
{
    return *(int *)(data_ov008_02090f24 + 0x4f4);
}

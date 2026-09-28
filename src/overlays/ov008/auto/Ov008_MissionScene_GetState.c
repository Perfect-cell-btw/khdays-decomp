/* The mission scene's state word, or -1. */

extern char *data_ov008_02090fa4;
int Ov008_MissionScene_GetState(void)
{
    if (data_ov008_02090fa4 != 0) {
        return *(int *)(data_ov008_02090fa4 + 0x94f4);
    }
    return -1;
}

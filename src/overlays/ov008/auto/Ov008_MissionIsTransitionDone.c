extern char *data_ov008_02090f24;

int Ov008_MissionIsTransitionDone(void)
{
    if (*(int *)(data_ov008_02090f24 + 0x28) != 0) {
        return *(int *)(data_ov008_02090f24 + 0x2c) == 0;
    }

    return 0;
}

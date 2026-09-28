extern char *data_ov008_02090fa0;
extern int Ov008_IsMissionGroupStale(void);

int Ov008_CanConfirmMissionMenu(void)
{
    int result = 0;

    if (*(int *)(data_ov008_02090fa0 + 0x28) == 0) {
        if (Ov008_IsMissionGroupStale() != 0) {
            return 1;
        }
    }

    return result;
}

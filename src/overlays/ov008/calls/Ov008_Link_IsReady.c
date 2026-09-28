extern char *data_ov008_02090f24;
extern int Ov008_Link_IsLocal(void);

int Ov008_Link_IsReady(void)
{
    if (data_ov008_02090f24 == 0) {
        return 1;
    }

    if (Ov008_Link_IsLocal() != 0) {
        return 1;
    }

    return *(int *)(data_ov008_02090f24 + 0x4fc);
}

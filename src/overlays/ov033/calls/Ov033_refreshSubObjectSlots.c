extern void ReleaseField74AndCleanup();
extern void *data_ov033_020b4b80;

void Ov033_refreshSubObjectSlots(void)
{
    char *base = (char *)*(int *)&data_ov033_020b4b80 + 0x2c2c;
    int i;
    char *p;
    ReleaseField74AndCleanup(base + 0xc);
    p = base + 0x120;
    i = 0;
    do {
        ReleaseField74AndCleanup(p);
        i++;
        p += 0x110;
    } while (i < 6);
}

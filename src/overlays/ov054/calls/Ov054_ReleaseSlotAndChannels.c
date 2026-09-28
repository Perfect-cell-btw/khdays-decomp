extern void *data_ov054_020b74a0;
extern void ReleaseField74AndCleanup(void *p);
extern void Ov054_freeSubObjectChannels(char *a);

void Ov054_ReleaseSlotAndChannels(char *a) {
    ReleaseField74AndCleanup((char *)data_ov054_020b74a0 + 0x2cb8);
    Ov054_freeSubObjectChannels(a);
}

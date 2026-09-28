extern int MI_CpuCopy8();

extern char data_020429c8[];

void CopyToSlotTable8(void *dst, int idx) {
    if (idx < 0) return;
    if (idx >= 4) return;
    MI_CpuCopy8(dst, data_020429c8 + idx * 8, 8);
}

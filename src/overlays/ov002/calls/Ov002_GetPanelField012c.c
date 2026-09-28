/* If status bit 2 of (*global)+0x12c is set, run Ov002_RetuneAmbientEmitter. */
extern void Ov002_RetuneAmbientEmitter(void);
extern int data_ov002_0207f614;

void Ov002_GetPanelField012c(void) {
    int base = *(int *)&data_ov002_0207f614;
    if ((*(unsigned int *)(base + 0x12c) << 0x1d) >> 0x1f) {
        Ov002_RetuneAmbientEmitter();
    }
}

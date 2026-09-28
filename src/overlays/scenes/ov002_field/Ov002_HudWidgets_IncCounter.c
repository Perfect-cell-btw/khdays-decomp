/* Bump the counter at (*global)+0x1028, unless the global is null. */
extern int data_ov002_0207f628;

void Ov002_HudWidgets_IncCounter(void) {
    int base = *(int *)&data_ov002_0207f628;
    if (base != 0) {
        *(int *)(base + 0x1028) += 1;
    }
}

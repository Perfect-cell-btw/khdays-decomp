extern int data_ov002_0207f614;

void Ov002_RequestCrawlSkip(void) {
    *(int *)(*(int *)&data_ov002_0207f614 + 0x48) = 1;
}

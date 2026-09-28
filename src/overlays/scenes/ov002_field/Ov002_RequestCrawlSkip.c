/* Sets a request flag of the object a global points to. */

extern int data_ov002_0207f614;

void Ov002_RequestCrawlSkip(void) {
    *(int *)(*(int *)&data_ov002_0207f614 + 0x48) = 1;
}

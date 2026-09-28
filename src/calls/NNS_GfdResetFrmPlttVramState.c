extern int data_02047364;

void NNS_GfdResetFrmPlttVramState(void) {
    *(int *)&data_02047364 = 0;
    *(int *)((char *)&data_02047364 + 4) = *(int *)((char *)&data_02047364 + 8);
}

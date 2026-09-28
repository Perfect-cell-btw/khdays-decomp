extern int data_ov002_0207fa10;

signed char Ov002_GetActorSlotByte(int arg0) {
    return *(signed char *)(*(int *)&data_ov002_0207fa10 + arg0 + 0xf);
}

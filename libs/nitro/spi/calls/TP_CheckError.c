extern int data_02046390;

int TP_CheckError(int arg0) {
    return *(unsigned short *)((char *)&data_02046390 + 0x38) & arg0;
}

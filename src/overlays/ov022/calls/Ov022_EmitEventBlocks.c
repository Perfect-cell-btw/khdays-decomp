extern void Ov022_MarshalNetworkRecord(int obj, int kind, int *buf, int size, unsigned int a, int b);
void Ov022_EmitEventBlocks(int obj, int param_2, unsigned int param_3, int *param_4) {
    unsigned int f;
    if (*(unsigned char *)(obj + 0x26c4) == 0) return;
    f = *(unsigned int *)(obj + 0x26bc);
    if ((f & 5) != 0) return;
    if ((f & 0x10) != 0) {
        Ov022_MarshalNetworkRecord(obj, 7, param_4, 0x1000, param_3, 0);
        return;
    }
    if ((f & 8) == 0) {
        Ov022_MarshalNetworkRecord(obj, 0, param_4, 0x1000, param_3, param_2);
        if ((*(unsigned int *)(obj + 0x26bc) & 2) != 0)
            Ov022_MarshalNetworkRecord(obj, 2, param_4, 0x1000, param_3, param_2);
    }
    *(unsigned long long *)obj |= 0x400000LL;
}

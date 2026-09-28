extern void Ov002_ParkSpareEntry(void *obj);

void Ov017_DispatchOnField4c(void *obj) {
    unsigned short v = *(unsigned short *)(*(int *)((char *)obj + 8) + 0x4c);
    if (v == 8) goto call1;
    if (v == 0x15) goto call2;
    return;
call1:
    Ov002_ParkSpareEntry(obj);
    return;
call2:
    Ov002_ParkSpareEntry(obj);
    return;
}

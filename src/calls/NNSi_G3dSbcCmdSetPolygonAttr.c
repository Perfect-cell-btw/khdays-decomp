extern void NNSi_G3dGeBufferCommand1(int arg0, unsigned char arg1);

void NNSi_G3dSbcCmdSetPolygonAttr(int *ptr) {
    int flags = ptr[2];

    if ((flags & 0x200) == 0 && (flags & 1) != 0 && (flags & 0x100) == 0) {
        NNSi_G3dGeBufferCommand1(0x14, *(unsigned char *)(ptr[0] + 1));
    }

    ptr[0] += 2;
}

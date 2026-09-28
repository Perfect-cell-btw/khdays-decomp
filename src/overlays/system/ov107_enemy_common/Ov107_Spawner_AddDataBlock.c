/* Copies a data block into the spawner's next block slot (up to 8); returns its index or -1. */

extern void *CallocInstance(int size);
extern void MI_CpuCopy8(const void *src, void *dst, unsigned int size);

int Ov107_Spawner_AddDataBlock(void *self, int size, void *src) {
    short idx = *(short *)((char *)self + 0xb0);
    void *buf;

    if (idx >= 8) return -1;
    buf = *(void **)((char *)self + idx * 8 + 0xb4) = CallocInstance(size);
    MI_CpuCopy8(src, buf, size);
    *(int *)((char *)self + 0xb8 + idx * 8) = size;
    *(short *)((char *)self + 0xb0) = *(short *)((char *)self + 0xb0) + 1;
    return idx;
}

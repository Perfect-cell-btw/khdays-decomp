extern void FreeAllListNodeSubBuffers();

void Ov025_ResetElevenEntries(int arg0) {
    int i = 0;
    int p = arg0 + 0x30;
    do {
        FreeAllListNodeSubBuffers(p);
        i++;
        p += 0x3c;
    } while (i < 0xb);
}

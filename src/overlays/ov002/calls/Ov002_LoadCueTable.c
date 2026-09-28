extern int Archive_LoadFile();
extern int Ov002_RelocateResourceHeader();
extern int data_ov002_0207eec4;
extern int data_ov002_0207f9f8;

void Ov002_LoadCueTable(void) {
    data_ov002_0207f9f8 = Archive_LoadFile(&data_ov002_0207eec4, 0xf);
    Ov002_RelocateResourceHeader();
}

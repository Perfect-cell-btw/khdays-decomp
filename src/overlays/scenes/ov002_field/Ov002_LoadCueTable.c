/* Loads the cue table file (kind 0xf) and relocates its resource header. */

extern int Archive_LoadFile();
extern int Ov002_RelocateResourceHeader();
extern int data_ov002_0207eec4;
extern int data_ov002_0207f9f8;

void Ov002_LoadCueTable(void) {
    int file = Archive_LoadFile(&data_ov002_0207eec4, 0xf);
    data_ov002_0207f9f8 = file;
    Ov002_RelocateResourceHeader(file);
}

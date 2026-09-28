extern int data_ov002_0207fa0c;
extern int Archive_LoadFile();

void Ov002_LoadGateModelTable(int arg0) {
    data_ov002_0207fa0c = Archive_LoadFile(arg0, 2);
}

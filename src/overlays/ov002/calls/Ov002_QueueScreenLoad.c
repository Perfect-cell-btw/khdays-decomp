extern int Ov002_AppendEntry();
extern int data_ov002_0207ee38;
extern int Ov002_ApplyLoadedScreen();

int Ov002_QueueScreenLoad(void) {
    return Ov002_AppendEntry(&data_ov002_0207ee38, Ov002_ApplyLoadedScreen, 0);
}

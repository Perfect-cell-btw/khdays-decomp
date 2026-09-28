extern int Ov002_ElementTickTearDown();
extern int Ov002_DoneTick();

int Ov002_Element_PickTick(int arg0) {
    int b = *(unsigned char *)(arg0 + 0x1b4);
    if (b == 5) {
        return (int)Ov002_ElementTickTearDown;
    }
    if (b == 7) {
        return (int)Ov002_DoneTick;
    }
    return 0;
}

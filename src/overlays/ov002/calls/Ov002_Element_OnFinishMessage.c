extern int Ov002_ElementFinishWithMode();

void Ov002_Element_OnFinishMessage(int arg0, int arg1) {
    if (*(unsigned char *)arg1 != 1) {
        return;
    }
    *(unsigned char *)(arg0 + 0x1c2) = *(unsigned char *)(arg1 + 4) == 3;
    Ov002_ElementFinishWithMode(arg0, *(unsigned char *)(arg1 + 4));
}

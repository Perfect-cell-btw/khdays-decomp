extern int Ov002_MovePieceToSlot();

void Ov002_Element_OnMessage(int arg0, int arg1) {
    if (*(unsigned char *)arg1 != 1) {
        return;
    }
    Ov002_MovePieceToSlot(arg0, *(unsigned char *)(arg1 + 9));
}

void Ov002_Element_Deactivate(int arg0) {
    if (*(unsigned short *)(arg0 + 0x12) & 2) {
        void (*f)(int) = *(void (**)(int))(*(int *)(arg0 + 8) + 0xc);
        if (f != 0) {
            f(arg0);
        }
        *(unsigned short *)(arg0 + 0x12) &= ~2;
    }
}

void Ov002_Element_Activate(int arg0) {
    if ((*(unsigned short *)(arg0 + 0x12) & 4) == 0) {
        void (*f)(int) = *(void (**)(int))(*(int *)(arg0 + 8) + 0x18);
        if (f != 0) {
            f(arg0);
        }
        *(unsigned short *)(arg0 + 0x12) |= 4;
    }
}

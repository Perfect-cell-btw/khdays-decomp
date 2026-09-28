struct S {
    char pad[0x1c];
    int field_1c;
    int field_20;
    int field_24;
    unsigned char field_28;
};

void Srt_SetScaleXYZ(struct S *p, int a, int b, int c) {
    p->field_1c = a;
    p->field_20 = b;
    p->field_24 = c;
    p->field_28 &= ~1;
    p->field_28 &= ~2;
}

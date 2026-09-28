extern int func_02032444();
extern void Slot_SetMode2Bit();
extern void Slot_SetVisible();

int Ov011_AllocAndRegisterObject(int this_, int arg1) {
    int obj = func_02032444(this_, arg1, 0);
    Slot_SetMode2Bit(this_, obj, 0);
    Slot_SetVisible(this_, obj, 0);
    return obj;
}

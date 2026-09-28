extern void DestroyInstance(int obj);
extern void Ov107_DestroyObject(int obj);

typedef struct {
    int field_00;
    int field_04;
} Pair8;

void Ov248_Destroy_2(int obj) {
    int i;
    for (i = 0; i < 2; i++) {
        DestroyInstance(((Pair8 *)obj)[i + 0x71].field_00);
    }
    Ov107_DestroyObject(obj);
}

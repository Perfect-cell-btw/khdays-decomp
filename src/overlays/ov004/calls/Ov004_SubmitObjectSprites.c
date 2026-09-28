typedef unsigned char u8;

typedef struct Ov004Context {
    u8 pad_0000[0x5544];
    void *objects[3];
} Ov004Context;

extern Ov004Context *data_ov004_02051384;

extern void ClampToRange0to16At0x4628(void *manager, int value);
extern void Obj_CommitAlphaBlend(void *manager, void *object);
extern void Obj_CommitAllSlots(void *manager);

void Ov004_SubmitObjectSprites(void) {
    int i;

    ClampToRange0to16At0x4628((char *)data_ov004_02051384 + 0xb0c, 0);
    for (i = 0; i < 3; i++) {
        Obj_CommitAlphaBlend((char *)data_ov004_02051384 + 0xb0c,
                      data_ov004_02051384->objects[i]);
    }
    Obj_CommitAllSlots((char *)data_ov004_02051384 + 0xb0c);
}


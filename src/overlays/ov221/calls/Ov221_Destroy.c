/* Frees the resource tables, destroys the model, the child selector and the eight attached
 * instances, then the base object. */

extern int FreeAllResourceTables();
extern int DestroyInstance();
extern int Ov107_ActionResource_Destroy();
extern int Ov107_DestroyObject();

struct Elem {
    int val;
    int pad;
};

struct Obj {
    char pad0[0x384];
    int field_384;   /* 0x384 */
    int field_388;   /* 0x388 */
    char pad1[8];
    int field_394;   /* 0x394 */
    char pad2[0x3fc - 0x394 - 4];
    int field_3fc;   /* 0x3fc */
    char pad3[0x424 - 0x3fc - 4];
    struct Elem arr[8]; /* 0x424, stride 8 bytes */
};

void Ov221_Destroy(struct Obj *r5)
{
    int i;

    FreeAllResourceTables(&r5->field_388);
    r5->field_394 = 0;
    DestroyInstance(r5->field_384);
    Ov107_ActionResource_Destroy(r5->field_3fc);

    for (i = 0; i < 8; i++) {
        if (r5->arr[i].val != 0) {
            DestroyInstance(r5->arr[i].val);
        }
    }

    Ov107_DestroyObject(r5);
}

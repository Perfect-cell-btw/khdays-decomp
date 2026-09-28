/* Destroys the model and the two attached instances, then the base object. */

extern int DestroyInstance();
extern int Ov107_DestroyObject();

struct S {
    char pad[0x394];
    int arr[2][2];
};

int Ov147_Destroy(struct S *r5) {
    int i;
    DestroyInstance(*(int *)((char *)r5 + 0x384));
    for (i = 0; i < 2; i++) {
        DestroyInstance(r5->arr[i][0]);
    }
    return Ov107_DestroyObject(r5);
}

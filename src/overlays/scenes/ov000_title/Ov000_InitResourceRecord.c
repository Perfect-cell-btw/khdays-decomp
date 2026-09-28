extern void MI_CpuFill8();
extern int *Archive_LoadFile();

typedef struct {
    int *field0;
    int field4;
    int field8;
} Struct;

void Ov000_InitResourceRecord(void *a, int b) {
    Struct *s = (Struct *)a;
    int *p;
    int t;
    MI_CpuFill8(a, 0, 12);
    p = Archive_LoadFile(b, 14);
    s->field0 = p;
    t = p[0];
    s->field4 = p[1];
    s->field8 = (int)s->field0 + t;
}

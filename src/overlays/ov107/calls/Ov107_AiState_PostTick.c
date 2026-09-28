extern void *List_First(void *list);
extern void Ov107_HitShape_UpdateWorld(int v);
extern void *List_Next(void *list);

typedef struct { int w0, w1, w2; } Word3;
extern Word3 data_02041dc8;

typedef struct {
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char bit2 : 1;
    unsigned char rest : 5;
} Flags17a;

void Ov107_AiState_PostTick(char *self) {
    if (*(int *)(self + 0x50) == 1) {
        Flags17a *f = (Flags17a *)(self + 0x17a);
        f->bit1 = f->bit2;
    }

    unsigned int flags = (unsigned)(*(unsigned short *)(self + 0x60) << 24) >> 24;
    if ((flags & 1) != 0 && (flags & 2) == 0) {
        void *node = List_First(self + 0x144);
        while (node != 0) {
            if (*(int *)node != 0) {
                Ov107_HitShape_UpdateWorld(*(int *)node);
            }
            node = List_Next(self + 0x144);
        }
    }

    *(Word3 *)(self + 0xd8) = data_02041dc8;
}

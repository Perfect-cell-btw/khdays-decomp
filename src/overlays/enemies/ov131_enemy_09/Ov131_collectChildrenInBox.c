extern void Ov131_collectObjectsInSphereRec(void *pt, int a, int b, int c, int *bounds, int *rect, int *count, int param3);

int Ov131_collectChildrenInBox(int param_1, int *param_2, int param_3) {
    struct { int pt[2]; int count; int rect[4]; } f;
    int i;
    f.count = 0;
    f.rect[0] = param_2[0] - param_2[3];
    f.rect[1] = param_2[2] - param_2[3];
    f.rect[2] = param_2[0] + param_2[3];
    f.rect[3] = param_2[2] + param_2[3];
    for (i = 0; i < *(unsigned short *)(param_1 + 2); i++) {
        int e = ((int *)(*(int *)(param_1 + 4)))[i];
        if ((*(unsigned short *)(e + 0x74) & 0x2000) == 0) {
            f.pt[0] = *(int *)(e + 0x84);
            f.pt[1] = *(int *)(e + 0x88);
            Ov131_collectObjectsInSphereRec(f.pt, *(int *)(e + 0x8c), *(int *)(e + 0x9c),
                                *(int *)(e + 0xa4), param_2, f.rect, &f.count, param_3);
            if (f.count >= 4) break;
        }
    }
    return f.count;
}

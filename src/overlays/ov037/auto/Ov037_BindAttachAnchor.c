void Ov037_BindAttachAnchor(char *r0, char *r1) {
    *(int **)(r1 + 0x10c) = (int *)(*(char **)(r0 + 0x263c) + 4);
}

/* Points the effect block's attach anchor at the character's attachment point. */

void Ov056_BindAttachAnchor(char *r0, char *r1) {
    *(int **)(r1 + 0x10c) = (int *)(*(char **)(r0 + 0x263c) + 4);
}

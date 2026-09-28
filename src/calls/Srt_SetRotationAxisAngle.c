extern void QuatFromAxisAngle(void *);

void Srt_SetRotationAxisAngle(void *param_1) {
    QuatFromAxisAngle(param_1);
    *((unsigned char *)param_1 + 0x28) &= ~1;
}

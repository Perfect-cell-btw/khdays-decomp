/* Sets an SRT's rotation from an axis and angle and marks the rotation as non-identity. */

extern void QuatFromAxisAngle(void *, int *, int);

void Srt_SetRotationAxisAngle(void *param_1, int *arg1, int arg2) {
    QuatFromAxisAngle(param_1, arg1, arg2);
    *((unsigned char *)param_1 + 0x28) &= ~1;
}

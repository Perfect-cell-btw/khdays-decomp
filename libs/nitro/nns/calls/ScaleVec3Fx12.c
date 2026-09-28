void ScaleVec3Fx12(int factor, int *src, int *dst) {
    dst[0] = (int)(((long long)factor * src[0]) >> 12);
    dst[1] = (int)(((long long)factor * src[1]) >> 12);
    dst[2] = (int)(((long long)factor * src[2]) >> 12);
}

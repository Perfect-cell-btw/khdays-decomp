/* Whether the rotation is in state 2 or 3, or (when asked) idle with time left. */

int func_ov022_02092dc8(int arg0, int arg1) {
    if ((unsigned char)(*(unsigned char *)(arg0 + 0x135) + 0xfe) <= 1) return 1;
    if (arg1 != 0 && *(unsigned char *)(arg0 + 0x135) == 0 && *(int *)(arg0 + 0x174) > 0) return 1;
    return 0;
}

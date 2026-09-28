extern void TextCanvas_DrawShadowed(void *ptr, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6);

void TextCanvas_DrawShadowedAt(char *ptr, int arg1, int arg2, int arg3, int arg4, int arg5) {
    TextCanvas_DrawShadowed(ptr + 0x1c, arg1, arg2, arg3, arg4, arg5, 0);
}

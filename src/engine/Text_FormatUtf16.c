/* Variadic forwarder: passes its three named arguments plus a va_list onto Text_VSNPrintfWide. */
extern void Text_VSNPrintfWide(int a, int b, int c, void *ap);

void Text_FormatUtf16(int a, int b, int c, ...) {
    Text_VSNPrintfWide(a, b, c, (void *)(((unsigned int)&c & ~3u) + 4));
}

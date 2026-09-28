/* Forward five arguments to TextCanvas_DrawShadowed against the sub-object at +0x1c, appending a
 * trailing 1. Named for the forwarding it does -- TextCanvas_DrawShadowed is still an ASM stub, so
 * its semantics are not yet available to name this after. */

extern void TextCanvas_DrawShadowed(void *ptr, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6);

void Obj_ForwardToSub1c(char *ptr, int arg1, int arg2, int arg3, int arg4, int arg5) {
    TextCanvas_DrawShadowed(ptr + 0x1c, arg1, arg2, arg3, arg4, arg5, 1);
}

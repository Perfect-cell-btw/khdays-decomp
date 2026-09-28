/* Draws a glyph with the object's inner text engine (Text_DrawGlyph). */

extern void Text_DrawGlyph(void *ptr, int word0, int arg1, int arg2, int arg3, unsigned short arg4);

void Obj_ForwardInnerPayload(int *ptr, int arg1, int arg2, int arg3, unsigned short arg4) {
    Text_DrawGlyph((char *)ptr[6] + 8, ptr[0], arg1, arg2, arg3, arg4);
}

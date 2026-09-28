/* Draws a glyph with the object's inner text engine (Text_DrawGlyph). Returns the glyph's advance.
 */

extern int Text_DrawGlyph(void *ptr, int word0, int arg1, int arg2, int arg3, unsigned short arg4);

int Obj_ForwardInnerPayload(int *ptr, int arg1, int arg2, int arg3, unsigned short arg4) {
    return Text_DrawGlyph((char *)ptr[6] + 8, ptr[0], arg1, arg2, arg3, arg4);
}

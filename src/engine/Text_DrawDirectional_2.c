/*
 * Text_DrawDirectional - draw text with the writing direction taken from the font layout mode.
 *
 * Reads the font's layout-mode byte (glyphTable[7], the same selector the glyph blitter
 * Text_DrawGlyph uses) and resolves it into a unit writing-direction vector dir=(dx,dy):
 *   mode 0/7 -> (+1, 0) left-to-right     mode 1/2 -> (0, +1) top-to-bottom
 *   mode 3/4 -> (-1, 0) right-to-left     mode 5/6 -> (0, -1) bottom-to-top
 *   other    -> (0, 0)
 * then forwards to the block align+layout anchor Text_AlignAnchor with the scene's text
 * context (self + 0x1c). The font pointer chain is self->0x20 -> [0] -> [+8] = glyphTable.
 *
 * dir is a 2-byte by-value struct {s8 dx, dy}; sibling of Text_DrawDirectional_2 (which takes the
 * axis offset explicitly instead of deriving it).
 */

typedef struct { signed char dx, dy; } TextDir;

extern void Text_AlignAnchor(int *ctx, int x, int y, int p4, unsigned int flags, int p6, TextDir dir);

void Text_DrawDirectional_2(int self, int x, int y, int p4, unsigned int flags, int p6)
{
    int *p = *(int **)(self + 0x20);
    TextDir dir = {0, 0};

    switch (*(unsigned char *)(*(int *)(*p + 8) + 7)) {
    case 0:
    case 7:
        dir.dx = 1;
        break;
    case 1:
    case 2:
        dir.dy = 1;
        break;
    case 3:
    case 4:
        dir.dx = -1;
        break;
    case 5:
    case 6:
        dir.dy = -1;
        break;
    }
    Text_AlignAnchor((int *)(self + 0x1c), x, y, p4, flags, p6, dir);
}

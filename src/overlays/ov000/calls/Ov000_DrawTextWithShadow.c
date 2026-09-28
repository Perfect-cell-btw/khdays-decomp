typedef struct {
    int color;
    unsigned int flags;
} DrawTextStyle;

extern void Text_DrawDirectional_2(
    int context,
    int x,
    int y,
    int color,
    unsigned int flags,
    int textHandle);

void Ov000_DrawTextWithShadow(
    int context,
    int textHandle,
    int x,
    int y,
    DrawTextStyle style)
{
    Text_DrawDirectional_2(
        context,
        x + 1,
        y + 1,
        style.color - 1,
        style.flags,
        textHandle);
    Text_DrawDirectional_2(
        context,
        x,
        y,
        style.color,
        style.flags,
        textHandle);
}

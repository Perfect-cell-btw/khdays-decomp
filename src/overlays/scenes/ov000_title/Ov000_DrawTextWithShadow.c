/* Draw one text handle twice: first offset by (+1,+1) in colour-1 as the drop shadow, then at (x,y)
 * in the requested colour. The style (colour + flags) arrives as a by-value struct, which is why
 * the two words are read from the stack rather than held in registers. */

#include "game/engine.h"

typedef struct {
    int color;
    unsigned int flags;
} DrawTextStyle;

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

/* Enables the global colour scale and sets each channel to its RGB555 component + 1. */

#include "nitro/types.h"

typedef struct MaterialColorScale {
    u16 red;
    u16 green;
    u16 blue;
} MaterialColorScale;

extern MaterialColorScale data_027e0658;
extern u16 data_027e0654;

void MaterialColorScale_SetRgb555(int value)
{
    data_027e0654 = 1;
    data_027e0658.red = (value & 0x1f) + 1;
    data_027e0658.green = ((value >> 5) & 0x1f) + 1;
    data_027e0658.blue = ((value >> 10) & 0x1f) + 1;
}

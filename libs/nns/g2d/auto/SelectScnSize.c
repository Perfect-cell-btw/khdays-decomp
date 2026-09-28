

#include "nitro/types.h"
#include "nitro/os.h"
#include "nnsys/g2d.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

typedef struct ScreenSizeMap {
    u16 width;
    u16 height;
    u16 scnSize;
} ScreenSizeMap;

/* SelectScnSize -- NitroSystem g2d_Screen.c: SelectScnSize. */
const ScreenSizeMap * SelectScnSize (const ScreenSizeMap tbl[4], int w, int h)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (w <= tbl[i].width && h <= tbl[i].height) {
            return &tbl[i];
        }
    }
    return &tbl[3];
}

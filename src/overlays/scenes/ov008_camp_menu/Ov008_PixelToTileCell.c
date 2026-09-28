/* Maps a touch position in the grid area to its tile cell (5 columns, 8 rows); returns whether the
 * point was inside the grid. */

#include "nitro/types.h"

int Ov008_PixelToTileCell(u16 *pTileX, u16 *pTileY, unsigned int px, unsigned int py) {
    int ret = 0;
    if (px < 0x60 && py >= 0x10 && py < 0xa0) {
        int cx = px - 8;
        u16 tx;
        int cy;
        u16 ty;
        *pTileX = cx / 16;
        tx = *pTileX;
        if (tx > 4) tx = 4;
        *pTileX = tx;
        cy = py - 0x18;
        *pTileY = cy / 16;
        ty = *pTileY;
        ret = 1;
        if (ty > 7) ty = 7;
        *pTileY = ty;
    }
    return ret;
}

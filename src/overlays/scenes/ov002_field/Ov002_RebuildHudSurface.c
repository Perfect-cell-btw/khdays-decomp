/* Rebuild one of the HUD's tiled surfaces from a const config template.
 *
 * Copies the 40-byte TileSurfaceCfg template, patches its VRAM target and pixel source (allocated
 * for slot 0x1a), uploads it as a 4bpp TileSurface at base+0xe8, and raises the "present" flag on
 * the two contiguous surfaces (base+0xd4, stride 0x3c). base is the HUD object held at
 * data_ov002_0207f9fc.
 */

#include "nitro/types.h"

typedef struct {
    int nUnk00;
    int nUnk04;
    int nWidthTiles;
    int nHeightTiles;
    int nRowTiles;
    int nPaletteIndex;
    int nVramTarget;
    int nUnk1c;
    void *pPixels;
    int nUnk24;
} TileSurfaceCfg;

extern const TileSurfaceCfg data_ov002_0207e520;
extern int *data_ov002_0207f9fc;
extern void Ov002_BuildHudSurfaces(void);
extern int Ov002_GetItemResource(int slot);
extern void *Ov002_Hud_GetBlock30(void);
extern void Ov002_SelectEntry(int slot);
extern void TileSurface_InitAndUpload4bpp(void *surface, const TileSurfaceCfg *cfg);

void Ov002_RebuildHudSurface(void) {
    int base = (int)data_ov002_0207f9fc;
    TileSurfaceCfg cfg = data_ov002_0207e520;
    int i;

    Ov002_BuildHudSurfaces();
    cfg.nVramTarget = Ov002_GetItemResource(0x1a);
    cfg.pPixels = Ov002_Hud_GetBlock30();
    Ov002_SelectEntry(0x1a);
    TileSurface_InitAndUpload4bpp((void *)(base + 0xe8), &cfg);

    for (i = 0; i < 2; i++) {
        *(int *)(base + 0xd4) = 1;
        base += 0x3c;
    }
}

/* Ov008_LoadWeaponStats -- Ov008_LoadWeaponStats (168 B, 5 relocs).
 * Loads the equipped-weapon stat record for character `id` into a local 32-byte buffer via
 * Ov008_LoadCharacterWeapon (0208b890) and copies the stats into the page-B menu context. For a
 * valid id (>= 0) it resolves the equipped slot (Ov008_GetLocalPlayerCharacter, 0x13 -> 0) and loads that
 * weapon; for id < 0 it loads the default record (slot 0x13, id 0). Bails early if the page gate
 * (data_ov008_02090f20) is clear. Writes the id to pageB+0x1d8, then five signed-halfword stats to
 * pageB+0x1e0..0x1e6 (the first field picks buf.he vs buf.h2 by `flag`) and a u32 to pageB+0x1dc.
 * The page-B fields are signed 16-bit (ldrsh), and the 0x1e0/e2/e4/e6 group shares the pageB+0x100
 * base because the halfword store offset cannot reach 0x1e0 directly. */
typedef short s16;

/* Weapon-stat record filled by Ov008_LoadCharacterWeapon (0208b890); 32 bytes. */
typedef struct {
    s16  h0, h2, h4, h6;
    int  w8;
    s16  hc, he;
    char pad[16];
} Ov008WeaponBuf;

extern int  data_ov008_02090f20;
extern int  Ov008_GetPageB(void);
extern int  Ov008_GetLocalPlayerCharacter(void);
extern void Ov008_LoadCharacterWeapon(void *out, int slot, int id);

void Ov008_LoadWeaponStats(int id, int flag)
{
    Ov008WeaponBuf wbuf;
    int pageB;
    int slot;

    pageB = Ov008_GetPageB();
    if (data_ov008_02090f20 == 0)
        return;
    if (id >= 0) {
        slot = Ov008_GetLocalPlayerCharacter();
        if (slot == 0x13)
            slot = 0;
        Ov008_LoadCharacterWeapon(&wbuf, slot, id);
    } else {
        Ov008_LoadCharacterWeapon(&wbuf, 0x13, 0);
    }
    *(int *)(pageB + 0x1d8) = id;
    *(s16 *)(pageB + 0x1e0) = flag != 0 ? wbuf.he : wbuf.h2;
    *(s16 *)(pageB + 0x1e2) = wbuf.h4;
    *(s16 *)(pageB + 0x1e4) = wbuf.h6;
    *(int *)(pageB + 0x1dc) = wbuf.w8;
    *(s16 *)(pageB + 0x1e6) = wbuf.hc;
}

/* ov022 constructor argument block data_ov022_020b2604, 0x020b2604-0x020b2618 (.rodata).
 *
 * Five words handed to a class constructor: the resource path of the object's archive
 * ('ba/ef/re_h.p.z') and four parameters the constructor reads.  Used by Ov022_BuildEffectSlots.
 */

typedef struct ClassCtorArgs {
    const char *pszResource;  /* 0x00 */
    int aParam[4];            /* 0x04 */
} ClassCtorArgs;

extern char gOv022BaEfReHPackPath;  /* the path string */

const ClassCtorArgs data_ov022_020b2604 = {
    &gOv022BaEfReHPackPath,
    { 1, 0, 2048, 5 },
};

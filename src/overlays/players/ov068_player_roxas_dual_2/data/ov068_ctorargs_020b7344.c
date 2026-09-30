/* ov068 constructor argument block data_ov068_020b7344, 0x020b7344-0x020b7358 (.rodata).
 *
 * Five words handed to a class constructor: the resource path of the object's archive
 * ('ba/ch/r2/li_e2.p.z') and four parameters the constructor reads.  Used by Ov068_InitEffectSlots.
 */

typedef struct ClassCtorArgs {
    const char *pszResource;  /* 0x00 */
    int aParam[4];            /* 0x04 */
} ClassCtorArgs;

extern char gOv068RoxasDualLiE2PackPath;  /* the path string */

const ClassCtorArgs data_ov068_020b7344 = {
    &gOv068RoxasDualLiE2PackPath,
    { 4, 0, 0, 0 },
};

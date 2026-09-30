/* ov022 constructor argument block data_ov022_020b262c, 0x020b262c-0x020b2640 (.rodata).
 *
 * Five words handed to a class constructor: the resource path of the object's archive
 * ('ba/ef/mg.p.z') and four parameters the constructor reads.  Used by Ov022_BuildEffectSlots.
 */

typedef struct ClassCtorArgs {
    const char *pszResource;  /* 0x00 */
    int aParam[4];            /* 0x04 */
} ClassCtorArgs;

extern char gOv022BaEfMgPackPath;  /* the path string */

const ClassCtorArgs data_ov022_020b262c = {
    &gOv022BaEfMgPackPath,
    { 1, 0, 0, 5 },
};

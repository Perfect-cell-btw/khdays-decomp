/* ov079 constructor argument block data_ov079_020b9924, 0x020b9924-0x020b9938 (.rodata).
 *
 * Five words handed to a class constructor: the resource path of the object's archive
 * ('ba/ch/ma/li_e2.p.z') and four parameters the constructor reads.  Used by Ov079_SetupSequenceSlots.
 */

typedef struct ClassCtorArgs {
    const char *pszResource;  /* 0x00 */
    int aParam[4];            /* 0x04 */
} ClassCtorArgs;

extern char gOv079MarluxiaLiE2PackPath;  /* the path string */

const ClassCtorArgs data_ov079_020b9924 = {
    &gOv079MarluxiaLiE2PackPath,
    { 1, 0, 0, 0 },
};

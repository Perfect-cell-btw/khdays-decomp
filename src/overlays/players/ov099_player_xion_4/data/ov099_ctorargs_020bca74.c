/* ov099 constructor argument block data_ov099_020bca74, 0x020bca74-0x020bca88 (.rodata).
 *
 * Five words handed to a class constructor: the resource path of the object's archive
 * ('ba/ch/ro/li_e3.p.z') and four parameters the constructor reads.  Used by Ov099_initStateSlotsDispatch.
 */

typedef struct ClassCtorArgs {
    const char *pszResource;  /* 0x00 */
    int aParam[4];            /* 0x04 */
} ClassCtorArgs;

extern char gOv099RoxasLiE3PackPath;  /* the path string */

const ClassCtorArgs data_ov099_020bca74 = {
    &gOv099RoxasLiE3PackPath,
    { 3, 0, 0, 0 },
};

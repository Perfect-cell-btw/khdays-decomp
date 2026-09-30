/* ov030 constructor argument block data_ov030_020b58c4, 0x020b58c4-0x020b58d8 (.rodata).
 *
 * Five words handed to a class constructor: the resource path of the object's archive
 * ('ba/ch/ro/li_e3.p.z') and four parameters the constructor reads.  Used by Ov030_initStateSlotsDispatch.
 */

typedef struct ClassCtorArgs {
    const char *pszResource;  /* 0x00 */
    int aParam[4];            /* 0x04 */
} ClassCtorArgs;

extern char gOv030RoxasLiE3PackPath;  /* the path string */

const ClassCtorArgs data_ov030_020b58c4 = {
    &gOv030RoxasLiE3PackPath,
    { 3, 0, 0, 0 },
};

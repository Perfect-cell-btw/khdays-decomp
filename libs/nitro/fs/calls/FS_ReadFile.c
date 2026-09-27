/* NitroSDK fs (fs_file.c): FS_ReadFile -- FSi_ReadFileCore(p_file, dst, len, FALSE). */
extern void *FSi_ReadFileCore();

void *FS_ReadFile(int a, void *b, void *c) {
    return FSi_ReadFileCore(a, b, c, 0);
}

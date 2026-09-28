/* Closes an open file handle: clears the archive pointer, marks the slot free (0xe) and
 * drops the two state bits.  Returns 0 when the handle was not busy. */
extern int FSi_SendCommand(char *file, int flags);

int FS_CloseFile(char *file) {
    if (FSi_SendCommand(file, 8) == 0) {
        return 0;
    }
    *(int *)(file + 8) = 0;
    *(int *)(file + 0x10) = 0xe;
    *(int *)(file + 0xc) &= ~0x30;
    return 1;
}

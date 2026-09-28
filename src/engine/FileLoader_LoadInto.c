/* FileLoader_LoadInto -- load a file into a caller buffer through the loader thread, MAIN. Twin of
 * Loader_RequestFile for a fixed destination: the file (an id with bit 31 set, or a path whose
 * language placeholder Msg_BuildLangPath expands) is opened; a ".?Z" name or a compressed id is
 * decompressed into `buffer` (Loader_SetupLZDecompress, failing if it exceeds `maxSize`), anything else is
 * read raw when it fits. On success the request goes to the loader queue and the byte count is
 * returned; 0 when no request slot is free, -1 when the data does not fit. */
#include "nitro/types.h"

extern int *Loader_PopFreeRequest(void);
extern void FS_InitFile(void *file);
extern void FSi_WaitForCardThread(void);
extern int Archive_OpenSubfileByHandle(void *file, u32 id);
extern u32 Archive_SubfileIsCompressed(u32 param_1);
extern int strlen(const char *s);
extern char *Msg_BuildLangPath(char *name);
extern int FS_OpenFile(void *file, const char *path);
extern void *Loader_SetupLZDecompress(char *self, void *file, void *existing, int maxSize, int **heap, int id);
extern int FS_CloseFile(char *file);
extern int OS_SendMessage(char *q, void *msg, int flags);
extern char data_0204bc1c[];
extern const unsigned char data_02041c48[128];

static inline int toupper(int c)
{
    return (c < 0 || c >= 128) ? c : data_02041c48[c];
}

int FileLoader_LoadInto(const void *data, void *buffer, int maxSize)
{
    u32 file[0x12]; /* FSFile: [2] = start offset, [9] = image base, [10] = field_10 */
    int *self;
    int flag;

    self = Loader_PopFreeRequest();
    if (self == 0) {
        return 0;
    }

    FS_InitFile(file);
    FSi_WaitForCardThread();

    if ((u32)data & 0x80000000) {
        Archive_OpenSubfileByHandle(file, (u32)data);
        flag = (int)Archive_SubfileIsCompressed((u32)data);
    } else {
        int len = strlen((const char *)data);
        FS_OpenFile(file, Msg_BuildLangPath((char *)data));

        flag = 0;
        if (((const char *)data)[len - 2] == '.' &&
            toupper(((const char *)data)[len - 1]) == 'Z') {
            flag = 1;
        }
    }

    self[2] = file[2];
    self[3] = file[9];
    self[4] = file[10];

    if (flag != 0) {
        if (Loader_SetupLZDecompress((char *)self, file, buffer, maxSize, 0, 0) == 0) {
            goto fail;
        }
        self[1] = 1;
    } else {
        self[11] = self[4] - self[3];
        self[10] = (int)buffer;
        self[1] = 0;
        if (self[11] > maxSize) {
            goto fail;
        }
    }

    FS_CloseFile((char *)file);
    OS_SendMessage(data_0204bc1c, self, 1);
    return self[11];

fail:
    FS_CloseFile((char *)file);
    return -1;
}

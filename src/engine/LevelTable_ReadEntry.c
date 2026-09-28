/* Reads level entry `index` of a character (kind 0x14 uses slot 0, 0x15 slot 0xe, others their own
 * slot) from "ba/ch/<name>/lv.b.z" (data_02042a70 names) into *out, loading the file from heap 6
 * and freeing it again. */
#pragma thumb on

#include "nitro/types.h"

typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    u16 f8;
    int fc;
} LevelEntry;

extern int OS_SPrintf(char *dst, const char *fmt, ...);
extern void *Archive_LoadFile(const char *path, int heap);
extern void NNSi_FndFreeFromDefaultHeap(void *p);
extern char *data_02042a70[];
extern char data_02042ac0[];
extern char data_02042ad0[];

void LevelTable_ReadEntry(int kind, int index, LevelEntry *out)
{
    char path[0x80];
    LevelEntry *file;

    switch (kind) {
    case 0x14:
        kind = 0;
        break;
    case 0x15:
        kind = 0xe;
        break;
    }
    OS_SPrintf(path, data_02042ac0, data_02042ad0, data_02042a70[kind]);
    file = Archive_LoadFile(path, 6);
    {
        LevelEntry *e = &file[index];

        out->f0 = e->f0;
        out->f2 = e->f2;
        out->f4 = e->f4;
        out->f6 = e->f6;
        out->f8 = e->f8;
        out->fc = e->fc;
    }
    NNSi_FndFreeFromDefaultHeap(file);
}

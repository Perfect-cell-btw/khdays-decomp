extern int Loader_LoadOverlayInfo(void *info, int proc, int id);
extern int Loader_LoadOverlayImage(int a);
extern int FS_StartOverlay(void *info);
extern void FS_EndOverlay(char *overlay);
extern int FS_UnloadOverlayImage(void *p);
extern int Math_DivMod(void *a, int b);
extern void OS_Terminate(void);

extern int data_ov107_020cb6a0;
extern int data_ov107_020cb610[6];
extern void *data_ov107_020cb5f8[6];
extern unsigned char data_ov107_020cb6a4[];

typedef unsigned int u32;
extern u32 OVERLAY_113_ID[1];
#define FS_OVERLAY_ID_ov113 ((int)(u32)&(OVERLAY_113_ID))

typedef struct { int w[6]; } Block24;

typedef struct {
    int field_0;
    void *field_4;
    void *field_8;
} Info;

int Ov107_LoadEnemyOverlay(int idx, int base, Info *info) {
    if (data_ov107_020cb6a0 != 0) {
        Block24 ids = *(Block24 *)data_ov107_020cb610;
        Block24 ptrs = *(Block24 *)data_ov107_020cb5f8;
        char localInfo[0x2c];
        int i;

        data_ov107_020cb6a0 = 0;
        for (i = 0; i < 6; i++) {
            Loader_LoadOverlayInfo(localInfo, 0, ids.w[i]);
            Loader_LoadOverlayImage((int)localInfo);
            FS_StartOverlay(localInfo);
            *(char *)ptrs.w[i] = 0;
            FS_EndOverlay(localInfo);
            FS_UnloadOverlayImage(localInfo);
        }
    }

    {
        unsigned char *row = data_ov107_020cb6a4 + idx * 6;
        unsigned char b = row[base];
        int result;
        int r4;
        Loader_LoadOverlayInfo(info, 0, FS_OVERLAY_ID_ov113 + b + 1);
        result = Math_DivMod(info->field_8, 0x1e00);
        r4 = result + 1;
        if (base + r4 > 6) {
            OS_Terminate();
            return -1;
        }
        Loader_LoadOverlayImage((int)info);
        FS_StartOverlay(info);
        ((void (*)(void))info->field_4)();
        return r4;
    }
}

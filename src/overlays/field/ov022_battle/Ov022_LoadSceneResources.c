/* Sets up the render state, loads ov106, creates its registration instance from the template and
 * loads the shop table. */

typedef unsigned char u8;
typedef unsigned int u32;

extern u32 OVERLAY_106_ID[1];
#define FS_OVERLAY_ID_ov106 ((u32)(u32)&OVERLAY_106_ID)

typedef struct Ov022RegistrationBuffer {
    u8 payload[0x44];
    int handle;
} Ov022RegistrationBuffer;

typedef struct Ov022RegistrationState {
    u8 pad000[8];
    int handle;
} Ov022RegistrationState;

extern void Ov022_SetupRenderState(void);
extern void LoadOverlaySync(int arg0, int arg1);
extern int InstantiateClass(void *registrationClass,
                         Ov022RegistrationBuffer *buffer);
extern void Ov002_LoadShopTable(void);
extern u8 data_ov022_020b28bc[];
extern int data_ov106_020b8aa0;
extern Ov022RegistrationState data_ov022_020b2e60;

void Ov022_LoadSceneResources(void) {
    Ov022RegistrationBuffer buffer;

    Ov022_SetupRenderState();
    LoadOverlaySync(0, FS_OVERLAY_ID_ov106);
    {
        u32 remaining;
        const u8 *src;
        u8 *dst;

        src = data_ov022_020b28bc;
        dst = buffer.payload;
        remaining = 0x18;

        do {
            *dst = *src;
            src++;
            dst++;
            remaining--;
        } while (remaining != 0);
    }
    buffer.handle = 0;
    data_ov022_020b2e60.handle =
        InstantiateClass(&data_ov106_020b8aa0, &buffer);
    Ov002_LoadShopTable();
}

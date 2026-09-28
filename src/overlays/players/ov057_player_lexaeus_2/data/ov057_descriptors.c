/* ov057 semantic descriptors.
 *
 * gOv057SlotInitParams initializes actor slot 5 from the le/li_e3 resource.
 * gOv057SceneClass registers scene class 10/group 6 with a 0x3180-byte
 * auxiliary state block and the overlay's THUMB open/close hooks.
 */

typedef void (*GameClassFn)(void);

typedef struct {
    unsigned short nClassId;
    unsigned short nGroupId;
    GameClassFn pfnOpen;
    GameClassFn pfnClose;
    int nAuxSize;
    int *pArena;
} GameClassDescriptor;

typedef struct {
    char *pszResourcePath;
    int resourceKind;
    int reserved[3];
} Ov022SlotInitParams;

extern char data_ov057_020b73c0;
extern void Ov057_InitAndReturnNextState(void);
extern void Ov057_setupTriple(void);

const Ov022SlotInitParams data_ov057_020b738c = {
    &data_ov057_020b73c0,
    3,
    {0, 0, 0},
};

GameClassDescriptor data_ov057_020b73d4 = {
    10,
    6,
    Ov057_InitAndReturnNextState,
    Ov057_setupTriple,
    0x3180,
    0,
};

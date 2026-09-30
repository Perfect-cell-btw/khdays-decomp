/* Ov023_SceneRun -- Ov023_SceneRun: the running state of the event scene.  While the top
 * screen is active (+0x87590 == 0) the event script at +0x4b88 runs one step (Game_RunActionScript
 * 02020e58); once it ends the stream is closed (02020cc8) and, when its result word (+0x4cb4)
 * is 0, 1 or 2 (1 posting the word at +0x4cb8 to ov002 0206ba28), the scene winds down: the
 * game flag reset (02023560 0), in 3D mode (bit 3 of 02020a9c) the dual3d_update task removed
 * (02000fb4) and the camera block (+0x87554) released (0202e944), the main backgrounds set
 * up again (Ov023_SetupMainBackgrounds 02083100) and the closing state Ov023_SceneClose
 * (020830cc) returned.  With the bottom screen active, either the script is polled (02021884) while
 * +0x875e8 is clear, or the secondary script at +0x1511c runs one step and clears +0x875e8
 * when it ends.  Then per global mode: mode 4 steps the fade (Ov023_StepFade 02083758) and, in
 * a session (bits 1 / 2 of data_0204c240), either commits the sprite slots (0203253c on
 * +0x144) while game flag 0x248e is set or re-enters the display mode (Ov023_EnterDisplayMode
 * 020839b8, in a client session only while the lobby halfword data_0204c254 + 0xe is 0); modes
 * 4 and 0xc then update the active screen's boxes (020834c0 on +0x87590), release the
 * armed slots (02083690), refresh the boxes (020838b8) and, in a session (02030670), redraw
 * the sign-in panel (Ov023_DrawSignInPanel 02083334 on +0x12c).  0 to stay. */

#include "nitro/types.h"

typedef struct Ov023Scene {
    u8   pad_00000[0x12c];
    u8   panel[0x144 - 0x12c]; /* 0x0012c: the sign-in panel */
    u8   display[0x4b88 - 0x144]; /* 0x00144: the sprite slots */
    u8   script[0x4cb4 - 0x4b88]; /* 0x04b88: the event script stream */
    int  nResult;             /* 0x04cb4 */
    int  nResultArg;          /* 0x04cb8 */
    u8   pad_04cbc[0x1511c - 0x4cbc];
    u8   script2[0x87554 - 0x1511c]; /* 0x1511c: the secondary script stream */
    u8   camera[0x87590 - 0x87554]; /* 0x87554: the 3D camera block */
    int  nActiveScreen;           /* 0x87590 */
    u8   pad_87594[0x875e8 - 0x87594];
    int  nScript2Running;     /* 0x875e8 */
} Ov023Scene;

typedef struct Ov023SceneRoot {
    int  nField00;            /* 0x00 */
    Ov023Scene *pScene;       /* 0x04 */
} Ov023SceneRoot;

typedef struct Ov023Lobby {
    u8   pad_00[0xe];
    u16  nState;              /* 0x0e */
} Ov023Lobby;

extern int   Game_RunActionScript(void *pScript);                          /* Game_RunActionScript */
extern void  Obj_ResetBothSubBlocksAndArm(void *pScript);                          /* close a script stream */
extern void  Ov002_World_SetPendingEntryOnce(int nValue);
extern void  StoreToGlobalPtr4FieldE4IfSet(int nFlag);
extern int   LoadGlobalU16At0(void);                                   /* the global mode halfword */
extern void  VBlank_UnregisterCallback(int nPriority, const char *pName);      /* remove a named task */
extern void  Gfx_SetupSubEngine(void *pCamera);
extern void  Ov023_SetupMainBackgrounds(void);                             /* Ov023_SetupMainBackgrounds */
extern void  ScriptVm_UpdateActiveCamera(void *pScript);
extern void  Ov023_StepFade(void);                             /* Ov023_StepFade */
extern int   GameState_IsFlagSet(int nFlag);                              /* GameState_IsFlagSet */
extern void  Ov023_EnterDisplayMode(void);                             /* Ov023_EnterDisplayMode */
extern void  Obj_CommitAllSlots(void *pSlots);                           /* commit the sprite slots */
extern void  Ov023_DropPeer(int nPeer);                        /* Ov023_DropPeer */
extern void  Ov023_ReleaseArmedSlots(void);                             /* Ov023_ReleaseArmedSlots */
extern void  Ov023_ApplyScreenBlend(void);                             /* Ov023_RefreshBoxes */
extern int   Session_IsActive(void);                                   /* Session_IsActive */
extern void  Ov023_DrawSignInPanel(void *pPanel);                     /* Ov023_DrawSignInPanel */
extern void *Ov023_BeginClose(void);                             /* Ov023_SceneClose */
extern Ov023SceneRoot data_ov023_0208a784;
extern char  gOv023Dual3DUpdateName[];                                 /* "dual3d_update" */
extern u8    data_0204c240;                                         /* session bits */
extern Ov023Lobby data_0204c254;

void *Ov023_SceneRun(void)
{
    if (data_ov023_0208a784.pScene->nActiveScreen == 0) {
        if (Game_RunActionScript(data_ov023_0208a784.pScene->script) == 0) {
            Obj_ResetBothSubBlocksAndArm(data_ov023_0208a784.pScene->script);
            switch (data_ov023_0208a784.pScene->nResult) {
            case 1:
                Ov002_World_SetPendingEntryOnce(data_ov023_0208a784.pScene->nResultArg);
            case 0:
            case 2:
                StoreToGlobalPtr4FieldE4IfSet(0);
                if (LoadGlobalU16At0() & 8) {
                    VBlank_UnregisterCallback(1, gOv023Dual3DUpdateName);
                    Gfx_SetupSubEngine(data_ov023_0208a784.pScene->camera);
                }
                Ov023_SetupMainBackgrounds();
                return Ov023_BeginClose;
            }
        }
    } else if (data_ov023_0208a784.pScene->nScript2Running != 0) {
        if (Game_RunActionScript(data_ov023_0208a784.pScene->script2) == 0) {
            data_ov023_0208a784.pScene->nScript2Running = 0;
        }
    } else {
        ScriptVm_UpdateActiveCamera(data_ov023_0208a784.pScene->script);
    }
    switch (LoadGlobalU16At0()) {
    case 4:
        Ov023_StepFade();
        if (data_0204c240 & 4) {
            if (GameState_IsFlagSet(0x248e) == 0) {
                Ov023_EnterDisplayMode();
            } else {
                Obj_CommitAllSlots(data_ov023_0208a784.pScene->display);
            }
        } else if (data_0204c240 & 2) {
            if (data_0204c254.nState == 0) {
                Ov023_EnterDisplayMode();
            }
        }
    case 0xc:
        Ov023_DropPeer(data_ov023_0208a784.pScene->nActiveScreen);
        Ov023_ReleaseArmedSlots();
        Ov023_ApplyScreenBlend();
        if (Session_IsActive() != 0) {
            Ov023_DrawSignInPanel(data_ov023_0208a784.pScene->panel);
        }
        break;
    }
    return 0;
}

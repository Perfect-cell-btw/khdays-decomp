#include "game/class_descriptor.h"
/* main .data, 0x02042730-0x020427d4: the pause menu task's descriptor and resource names.
 *
 * The task class (0x12 / group 0xf, constructor 02022708, method 020227c0, 0xec-byte state) is
 * instantiated by 02022eb0; the screen files are the pause background (one per language, '&'
 * replaced by the two-letter code below), the icon and message tilemaps and the misc icons.
 */
extern void Boot3DSubsystem(void);
extern void Shutdown3DSubsystem(void);

/* The yes/no cursor of the pause menu confirmation page (02022eb0 defines and moves it; 1 = "no"). */
int data_02042730 = 1;

GameClassDescriptor data_02042734 = {
    0x12,  /* nClassId */
    0xf,   /* nGroupId */
    Boot3DSubsystem,  /* pfnCtor */
    Shutdown3DSubsystem,  /* pfnMethod */
    0xec,  /* nAuxSize */
    0,     /* pArena */
};

char gPauseRefreshName[16] = "pause_refresh";
char gPausePausebgPath[24] = "pause/pausebg_&.pbg.z";
char gPausePauseiconPath[24] = "pause/pauseicon.NSCR.z";
char gPausePausemsgPath[24] = "pause/pausemsg.NSCR.z";
char gPauseEtciconPath[24] = "pause/etcicon.NSCR.z";

/* The language suffixes of the pause background, in the game's language-id order. */
char gZhName[4] = "zh";
char gEnName[4] = "en";
char gItName[4] = "it";
char gDeName[4] = "de";
char gFrName[4] = "fr";
char gEsName[4] = "es";
char gJaName[4] = "ja";

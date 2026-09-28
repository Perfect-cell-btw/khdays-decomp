/* Ov006_MissionDriveSound -- Mission Mode: drive the ov105 sound state from the scene state.
 * State 0 (still booting) arms the "intro jingle started" latch at obj+0x49c once the
 * sound engine reports ready; states 1 and 3 are quiet; 9 and 10 fade out; every other
 * state stops the sound outright. */
extern int  Game_PollSceneAlive(void);
extern void Ov105_KickIdleHandler(void);
extern int  Ov105_WH_Initialize(void);
extern void Ov105_WH_Finalize(void);
extern int  data_ov006_020565e4;

#define OBJ (*(int **)&data_ov006_020565e4)

void Ov006_MissionDriveSound(void) {
    switch (Game_PollSceneAlive()) {
    case 9:
    case 10:
        Ov105_KickIdleHandler();
        return;
    case 0:
        if (OBJ[0x127] != 0) {
            return;
        }
        if (Ov105_WH_Initialize() == 0) {
            return;
        }
        OBJ[0x127] = 1;
        return;
    case 1:
        break;
    case 3:
        break;
    default:
        Ov105_WH_Finalize();
        return;
    }
}

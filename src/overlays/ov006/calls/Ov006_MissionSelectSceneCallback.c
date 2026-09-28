typedef void (*SceneCallback)(void);

extern int Game_PollSceneAlive(void);
extern void Ov105_WH_Finalize(void);
extern void Ov006_MissionSceneIdleCallback(void);

SceneCallback Ov006_MissionSelectSceneCallback(void) {
    SceneCallback callback = 0;

    switch (Game_PollSceneAlive()) {
    case 0:
    case 3:
        break;
    case 1:
        callback = Ov006_MissionSceneIdleCallback;
        break;
    default:
        Ov105_WH_Finalize();
        break;
    }

    return callback;
}

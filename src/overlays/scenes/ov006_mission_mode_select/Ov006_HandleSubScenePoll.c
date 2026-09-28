/* Ov006_HandleSubScenePoll -- react to the boot scene's poll result, ov006.
 * Polls whether the launched sub-scene is still alive (Game_PollSceneAlive/Game_PollSceneAlive):
 * result 1 latches the Mission Mode object's "advance" flag (base+0x49c); result 10 latches the
 * "abort" flag byte (base+0x4f0). Either transition returns the next state fn
 * (Ov006_MissionSceneIdleCallback); anything else stays (0). */
extern int  Game_PollSceneAlive(void);
extern int  data_ov006_020565e4;
extern void Ov006_MissionSceneIdleCallback(void);

void *Ov006_HandleSubScenePoll(void) {
    void *result = 0;
    int r = Game_PollSceneAlive();
    switch (r) {
    case 1:
        *(int *)(data_ov006_020565e4 + 0x49c) = 1;
        result = (void *)Ov006_MissionSceneIdleCallback;
        break;
    case 10:
        *(char *)(data_ov006_020565e4 + 0x4f0) = 1;
        result = (void *)Ov006_MissionSceneIdleCallback;
        break;
    }
    return result;
}

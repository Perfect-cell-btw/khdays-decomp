/* Ov008_HandleSubScenePoll -- react to the boot scene's poll result, ov006.
 * Polls whether the launched sub-scene is still alive (Game_PollSceneAlive/Game_PollSceneAlive):
 * result 1 latches the title object's "advance" flag (base+0x49c); result 10 latches the
 * "abort" flag byte (base+0x4f0). Either transition returns the next state fn
 * (Ov008_MissionSceneIdleCallback); anything else stays (0). */
extern int  Game_PollSceneAlive(void);
extern int  data_ov008_02090f24;
extern void Ov008_MissionSceneIdleCallback(void);

void *Ov008_HandleSubScenePoll(void) {
    void *result = 0;
    int r = Game_PollSceneAlive();
    switch (r) {
    case 1:
        *(int *)(data_ov008_02090f24 + 0x49c) = 1;
        result = (void *)Ov008_MissionSceneIdleCallback;
        break;
    case 10:
        *(char *)(data_ov008_02090f24 + 0x4f0) = 1;
        result = (void *)Ov008_MissionSceneIdleCallback;
        break;
    }
    return result;
}

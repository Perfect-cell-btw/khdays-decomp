/* Returns the object frame counter (data_0204c058 word 2), advanced by Obj_UpdateAll on every
 * frame that is not paused. */

extern int data_0204c058;

int Obj_GetFrameCount(void) {
    return *(int *)((char *)&data_0204c058 + 8);
}

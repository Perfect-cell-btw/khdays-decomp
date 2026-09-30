/* Returns the object frame counter (gObjSystem word 2), advanced by Obj_UpdateAll on every
 * frame that is not paused. */

extern int gObjSystem;

int Obj_GetFrameCount(void) {
    return *(int *)((char *)&gObjSystem + 8);
}

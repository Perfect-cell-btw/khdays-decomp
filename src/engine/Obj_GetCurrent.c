/* Returns the object whose callback is running (gObjSystem word 1): Obj_UpdateAll publishes each
 * object while it updates, Obj_Destroy while its destructor runs. */

extern int gObjSystem;

int Obj_GetCurrent(void) {
    return *(int *)((char *)&gObjSystem + 4);
}

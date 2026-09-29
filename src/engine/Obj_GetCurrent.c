/* Returns the object whose callback is running (data_0204c058 word 1): Obj_UpdateAll publishes each
 * object while it updates, Obj_Destroy while its destructor runs. */

extern int data_0204c058;

int Obj_GetCurrent(void) {
    return *(int *)((char *)&data_0204c058 + 4);
}

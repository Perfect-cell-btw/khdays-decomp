/* Scene vtable entry 9: returns the scene's +0x24 word. */

/* Read the chained field at (*(&data+4))+0x24. */
extern int data_ov027_02084360;
int Ov027_SceneGetField24(void) {
    return *(int *)(*(int *)((char *)&data_ov027_02084360 + 4) + 0x24);
}

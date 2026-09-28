/* Requests a scene: stores the pending scene id (+0x10) and the argument its class is
 * instantiated with (+0x14) in the scene-control record. Scene_AdvanceToPending switches to it
 * once the current scene has ended. */

extern int data_0204bda4;

void Scene_RequestPending(int arg0, int arg1) {
    *(int *)((char *)&data_0204bda4 + 0x10) = arg0;
    *(int *)((char *)&data_0204bda4 + 0x14) = arg1;
}

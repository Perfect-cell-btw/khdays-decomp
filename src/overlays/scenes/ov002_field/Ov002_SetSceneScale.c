/* Stores the value into a field of the context object a global points to. */

extern int data_ov002_0207fa20;

void Ov002_SetSceneScale(int arg0) {
    *(int *)(*(int *)((char *)&data_ov002_0207fa20 + 4) + 0x64) = arg0;
}

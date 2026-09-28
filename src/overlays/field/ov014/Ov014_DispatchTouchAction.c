extern void SceneNode_Disable(void *p);
extern void SceneNode_Enable(void *p);

void Ov014_DispatchTouchAction(char *obj, int sel) {
    switch (sel) {
        case 0:
            if ((*(int *)(obj + 0x38) & 0x20) == 0) SceneNode_Disable(obj + 0x3c);
            break;
        case 1:
            if ((*(int *)(obj + 0x38) & 0x20) == 0) SceneNode_Enable(obj + 0x3c);
            break;
        case 2:
            break;
    }
}

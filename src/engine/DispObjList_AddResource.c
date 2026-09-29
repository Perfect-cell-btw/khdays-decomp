/* Loads a sprite resource into a display-object list (Obj_LoadResourceNode); returns its index. */

extern int Obj_LoadResourceNode();

int DispObjList_AddResource(void *pList, void *b) {
    int list = (int)pList;
    return Obj_LoadResourceNode(list, b);
}

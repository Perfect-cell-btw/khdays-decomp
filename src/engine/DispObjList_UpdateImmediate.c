/* Updates a display-object list and uploads its OAM at once (DispObjList_Update, flush 1). */

extern int DispObjList_Update();

int DispObjList_UpdateImmediate(int list) {
    return DispObjList_Update(list, 1);
}

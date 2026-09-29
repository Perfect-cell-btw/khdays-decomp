/* Updates a display-object list and queues its OAM upload (DispObjList_Update, flush 0). */

extern int DispObjList_Update();

int DispObjList_UpdateQueued(int list) {
    return DispObjList_Update(list, 0);
}

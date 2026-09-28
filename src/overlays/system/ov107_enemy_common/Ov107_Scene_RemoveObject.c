/* Removes the object from the scene's object list. */

extern int List_First(int list);
extern int List_Next(int list);
extern int List_RemoveByHandle(int list, int handle);
extern char *data_ov107_020cbf1c;

void Ov107_Scene_RemoveObject(int obj) {
    char *self = data_ov107_020cbf1c;
    int list = (int)(self + 4);
    int handle = List_First(list);
    if (handle == 0) return;
    for (;;) {
        if (*(int *)handle == obj) {
            List_RemoveByHandle(list, handle);
            return;
        }
        handle = List_Next(list);
        if (handle == 0) return;
    }
}

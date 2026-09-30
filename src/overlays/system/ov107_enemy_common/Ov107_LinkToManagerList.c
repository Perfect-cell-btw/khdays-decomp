/* Links an item into the global manager's sorted list (gOv107ActorManager + 4). */

extern int *List_InsertSorted(int list, int stride, int max);
extern int *gOv107ActorManager;

void Ov107_LinkToManagerList(int item) {
    *List_InsertSorted((int)gOv107ActorManager + 4, 4, 100) = item;
}

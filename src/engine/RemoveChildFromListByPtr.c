/* Removes a child object from the object's child list (+0x88), dropping the list's reference;
 * returns its former index or -1. */

extern int *List_First();
extern void Obj_ReplaceRef();
extern void List_RemoveByHandle();
extern int *List_Next();
int RemoveChildFromListByPtr(int param_1, int *param_2, unsigned int param_3)
{
    int *node;
    int i;
    if (param_2 != 0) {
        i = 0;
        node = List_First(param_1 + 0x88);
        while (node != 0) {
            if ((int *)*node == param_2) {
                Obj_ReplaceRef(param_2, 0);
                List_RemoveByHandle(param_1 + 0x88, (int)node);
                return i;
            }
            i++;
            node = List_Next(param_1 + 0x88);
        }
    }
    return -1;
}

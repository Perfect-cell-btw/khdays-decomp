/* Links an item into the global manager's sorted list (data_ov107_020cbf1c + 4). */

extern int *List_InsertSorted(int list, int stride, int max);
extern int *data_ov107_020cbf1c;

void Ov107_LinkToManagerList(int item) {
    *List_InsertSorted((int)data_ov107_020cbf1c + 4, 4, 100) = item;
}

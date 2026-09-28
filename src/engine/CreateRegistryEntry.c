/* Creates a task in the registry: inserts a 0x28-byte entry, allocates its zeroed state block of
 * the given size, records its start and teardown callbacks and a new id; returns the id and
 * optionally the state block. */

extern int List_InsertSorted();
extern int *CallocInstance();
extern int data_02042ad8;
int CreateRegistryEntry(int param_1, unsigned int param_2, unsigned int param_3,
                  int param_4, int param_5, int *param_6)
{
    int *e = (int *)List_InsertSorted(param_1, 0x28, param_2);
    int id;
    *e = param_1;
    e[1] = (int)CallocInstance(param_3);
    e[5] = param_4;
    e[6] = param_5;
    e[9] = 0;
    id = data_02042ad8;
    data_02042ad8 = id + 1;
    e[7] = id;
    if (param_6 != 0)
        *param_6 = e[1];
    return e[7];
}

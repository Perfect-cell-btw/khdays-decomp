/* Calls entry 1 of the active handler B with the argument. */

extern int data_ov025_020b574c[];
extern char data_ov025_020b4a78[];

void Ov025_HandlerB_Call1(int arg0)
{
    int index = data_ov025_020b574c[1];

    if (index != -1) {
        ((void (*)(int))*(int *)(*(char **)(data_ov025_020b4a78 + index * 8) + 4))(arg0);
    }
}

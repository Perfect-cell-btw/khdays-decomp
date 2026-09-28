/* Calls entry 2 of the active handler B with the argument. */

extern int data_ov009_020563ec[];
extern char data_ov009_020562d4[];

void Ov009_HandlerB_Call2(int arg0)
{
    int index = data_ov009_020563ec[1];

    if (index != -1) {
        ((void (*)(int))*(int *)(*(char **)(data_ov009_020562d4 + index * 8) + 8))(arg0);
    }
}

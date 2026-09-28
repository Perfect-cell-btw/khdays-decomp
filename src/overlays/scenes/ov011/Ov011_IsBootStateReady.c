/* Whether the title scene is missing or in state 5. */

extern int data_ov011_0205e960;

int Ov011_IsBootStateReady(void) {
    int *p = *(int **)((char *)&data_ov011_0205e960 + 4);
    int r = 1;
    if (p != 0 && *(int *)((char *)p + 4) != 5) r = 0;
    return r != 0;
}

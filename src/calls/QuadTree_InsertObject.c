extern void QuadTree_Insert(int, int, int);

void QuadTree_InsertObject(int *param_1, int param_2) {
    if (param_1[0x27] == 0) {
        return;
    }
    QuadTree_Insert(param_1[0x27], (int)param_1 + 0x84, param_2);
}

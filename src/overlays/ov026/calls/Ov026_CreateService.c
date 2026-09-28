/* Instantiates the ov026 service class with the argument. */

extern int InstantiateClass(void *desc, int arg);
extern int data_ov026_02091200;
extern int *data_ov026_02091360;

void Ov026_CreateService(int arg0) {
    data_ov026_02091360[2] = InstantiateClass(&data_ov026_02091200, arg0);
}

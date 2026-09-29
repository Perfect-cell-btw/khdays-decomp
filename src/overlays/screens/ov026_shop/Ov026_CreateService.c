/* Instantiates the ov026 service class and stores it at +8 of the shop's state. The class's
 * constructor is what sets that state pointer, so the call has to come first: two statements say
 * so (in one assignment C leaves open which side is evaluated first). */
extern int InstantiateClass(void *desc, int arg);
extern int data_ov026_02091200;
extern int *data_ov026_02091360;
void Ov026_CreateService(int arg0) {
    int service = InstantiateClass(&data_ov026_02091200, arg0);
    data_ov026_02091360[2] = service;
}

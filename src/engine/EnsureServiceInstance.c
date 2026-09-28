/* Instantiates the service class once (id cached in data_02042978). */

extern int data_02042978;
extern int data_0204297c;
extern int InstantiateClass(void *ptr, int value);

void EnsureServiceInstance(void) {
    if (data_02042978 == -1) {
        data_02042978 = InstantiateClass(&data_0204297c, 0);
    }
}

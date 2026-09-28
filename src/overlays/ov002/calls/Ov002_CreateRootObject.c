/* Instantiate the overlay's root object with a single construction parameter and
 * keep its handle. Both globals are reached by ADDRESS, not by value -- the
 * class descriptor is the object itself, and the handle slot is written in
 * place. */
extern int InstantiateClass(void *classDesc, int *params);

extern int data_ov002_0207f024;
extern char data_ov002_0207f028[];

void Ov002_CreateRootObject(int param) {
    int params[1];

    params[0] = param;
    data_ov002_0207f024 = InstantiateClass(data_ov002_0207f028, params);
}
